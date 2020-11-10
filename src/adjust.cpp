#include "r.h"
#include "utils.h"
#include "zone.h"
#include "enums.h"
#include "conversion.h"
#include "resolve.h"
#include "local.h"
#include <date/date.h>
#include <date/tz.h>

// -----------------------------------------------------------------------------

static inline date::local_seconds adjust_switch(const date::local_seconds& lsec,
                                                const int& value,
                                                const r_ssize& i,
                                                const enum day_nonexistent& day_nonexistent,
                                                const enum adjuster& adjuster,
                                                bool& na);

static sexp adjust_zoned(sexp x,
                         sexp value,
                         const enum day_nonexistent& day_nonexistent,
                         const enum dst_nonexistent& dst_nonexistent,
                         const enum dst_ambiguous& dst_ambiguous,
                         const r_ssize& size,
                         const enum adjuster& adjuster);

[[cpp11::register]]
SEXP adjust_zoned_cpp(SEXP x,
                      SEXP value,
                      SEXP day_nonexistent,
                      SEXP dst_nonexistent,
                      SEXP dst_ambiguous,
                      SEXP size,
                      SEXP adjuster) {
  enum day_nonexistent c_day_nonexistent = parse_day_nonexistent(day_nonexistent);
  enum dst_nonexistent c_dst_nonexistent = parse_dst_nonexistent(dst_nonexistent);
  enum dst_ambiguous c_dst_ambiguous = parse_dst_ambiguous(dst_ambiguous);

  r_ssize c_size = r_int_get(size, 0);

  enum adjuster c_adjuster = parse_adjuster(adjuster);

  return adjust_zoned(
    x,
    value,
    c_day_nonexistent,
    c_dst_nonexistent,
    c_dst_ambiguous,
    c_size,
    c_adjuster
  );
}

static sexp adjust_zoned(sexp x,
                         sexp value,
                         const enum day_nonexistent& day_nonexistent,
                         const enum dst_nonexistent& dst_nonexistent,
                         const enum dst_ambiguous& dst_ambiguous,
                         const r_ssize& size,
                         const enum adjuster& adjuster) {
  sexp out = PROTECT(r_new_double(size));
  double* p_out = r_dbl_deref(out);

  sexp tzone = civil_get_tzone(x);
  tzone = PROTECT(zone_standardize(tzone));
  std::string zone_name = zone_unwrap(tzone);
  const date::time_zone* p_zone = zone_name_load(zone_name);

  r_poke_names(out, r_get_names(x));
  r_poke_class(out, civil_classes_posixct);
  civil_poke_tzone(out, tzone);

  const double* p_x = r_dbl_deref_const(x);
  const int* p_value = r_int_deref_const(value);

  const bool recycle_x = r_is_scalar(x);
  const bool recycle_value = r_is_scalar(value);

  for (r_ssize i = 0; i < size; ++i) {
    double elt_x = recycle_x ? p_x[0] : p_x[i];
    int elt_value = recycle_value ? p_value[0] : p_value[i];

    int64_t elt = as_int64(elt_x);

    if (elt == r_int64_na) {
      p_out[i] = r_dbl_na;
      continue;
    }

    if (elt_value == NA_INTEGER) {
      p_out[i] = r_dbl_na;
      continue;
    }

    std::chrono::seconds elt_sec{elt};
    date::sys_seconds elt_ssec{elt_sec};
    date::zoned_seconds elt_zsec = date::make_zoned(p_zone, elt_ssec);
    date::local_seconds elt_lsec = elt_zsec.get_local_time();

    bool na = false;

    date::local_seconds out_lsec = adjust_switch(
      elt_lsec,
      elt_value,
      i,
      day_nonexistent,
      adjuster,
      na
    );

    if (na) {
      p_out[i] = NA_REAL;
    } else {
      p_out[i] = convert_local_seconds_to_posixt(
        out_lsec,
        p_zone,
        i,
        dst_nonexistent,
        dst_ambiguous
      );
    }
  }

  UNPROTECT(2);
  return out;
}

// -----------------------------------------------------------------------------

static sexp adjust_local(sexp x,
                         sexp value,
                         const r_ssize& size,
                         const enum adjuster& adjuster);

[[cpp11::register]]
SEXP adjust_local_cpp(SEXP x,
                      SEXP value,
                      SEXP size,
                      SEXP adjuster) {
  r_ssize c_size = r_int_get(size, 0);

  enum adjuster c_adjuster = parse_adjuster(adjuster);

  return adjust_local(
    x,
    value,
    c_size,
    c_adjuster
  );
}

static inline void adjust_local_switch(const enum adjuster& adjuster,
                                       const r_ssize& i,
                                       const int& value,
                                       int* p_year,
                                       int* p_month,
                                       int* p_day,
                                       int* p_hour,
                                       int* p_minute,
                                       int* p_second);

static sexp adjust_local(sexp x,
                         sexp value,
                         const r_ssize& size,
                         const enum adjuster& adjuster) {
  x = PROTECT(r_maybe_clone(x));
  x = PROTECT(local_datetime_recycle(x, size));
  x = PROTECT(local_datetime_maybe_clone(x));

  int* p_year = r_int_deref(local_datetime_year(x));
  int* p_month = r_int_deref(local_datetime_month(x));
  int* p_day = r_int_deref(local_datetime_day(x));
  int* p_hour = r_int_deref(local_datetime_hour(x));
  int* p_minute = r_int_deref(local_datetime_minute(x));
  int* p_second = r_int_deref(local_datetime_second(x));

  const bool recycle_value = r_is_scalar(value);

  const int* p_value = r_int_deref_const(value);

  for (r_ssize i = 0; i < size; ++i) {
    if (p_year[i] == r_int_na) {
      continue;
    }

    int elt_value = recycle_value ? p_value[0] : p_value[i];

    if (elt_value == r_int_na) {
      p_year[i] = r_int_na;
      p_month[i] = r_int_na;
      p_day[i] = r_int_na;
      p_hour[i] = r_int_na;
      p_minute[i] = r_int_na;
      p_second[i] = r_int_na;
      continue;
    }

    adjust_local_switch(
      adjuster,
      i,
      elt_value,
      p_year,
      p_month,
      p_day,
      p_hour,
      p_minute,
      p_second
    );
  }

  UNPROTECT(3);
  return x;
}

// -----------------------------------------------------------------------------

static inline void check_value_adjust_year(const int& value) {
  if (value > 9999 || value < 0) {
    r_abort("`value` must be within the range of [0, 9999], not %i.", value);
  }
}
static inline void check_value_adjust_month(const int& value) {
  if (value > 12 || value < 1) {
    r_abort("`value` must be within the range of [1, 12], not %i.", value);
  }
}
static inline void check_value_adjust_day(const int& value) {
  if (value > 31 || value < 1) {
    r_abort("`value` must be within the range of [1, 31], not %i.", value);
  }
}
static inline void check_value_adjust_hour(const int& value) {
  if (value > 23 || value < 0) {
    r_abort("`value` must be within the range of [0, 23], not %i.", value);
  }
}
static inline void check_value_adjust_minute(const int& value) {
  if (value > 59 || value < 0) {
    r_abort("`value` must be within the range of [0, 59], not %i.", value);
  }
}
static inline void check_value_adjust_second(const int& value) {
  if (value > 59 || value < 0) {
    r_abort("`value` must be within the range of [0, 59], not %i.", value);
  }
}

// -----------------------------------------------------------------------------

static inline date::local_seconds adjust_hour(const date::local_seconds& lsec,
                                              const int& value) {
  check_value_adjust_hour(value);

  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  date::hh_mm_ss<std::chrono::seconds> hms = date::make_time(lsec - lsec_floor);

  date::local_seconds out_lsec =
    lsec_floor +
    std::chrono::hours{value} +
    hms.minutes() +
    hms.seconds();

  return out_lsec;
}

static inline date::local_seconds adjust_minute(const date::local_seconds& lsec,
                                                const int& value) {
  check_value_adjust_minute(value);

  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  date::hh_mm_ss<std::chrono::seconds> hms = date::make_time(lsec - lsec_floor);

  date::local_seconds out_lsec =
    lsec_floor +
    hms.hours() +
    std::chrono::minutes{value} +
    hms.seconds();

  return out_lsec;
}

static inline date::local_seconds adjust_second(const date::local_seconds& lsec,
                                                const int& value) {
  check_value_adjust_second(value);

  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  date::hh_mm_ss<std::chrono::seconds> hms = date::make_time(lsec - lsec_floor);

  date::local_seconds out_lsec =
    lsec_floor +
    hms.hours() +
    hms.minutes() +
    std::chrono::seconds{value};

  return out_lsec;
}

static inline date::local_seconds adjust_year(const date::local_seconds& lsec,
                                              const int& value,
                                              const r_ssize& i,
                                              const enum day_nonexistent& day_nonexistent,
                                              bool& na) {
  check_value_adjust_year(value);

  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  std::chrono::seconds time_of_day = lsec - lsec_floor;

  date::year_month_day ymd{lday};

  date::year_month_day out_ymd = date::year{value} / ymd.month() / ymd.day();

  if (!out_ymd.ok()) {
    bool na_resolve = false;

    resolve_day_nonexistent(i, day_nonexistent, out_ymd, time_of_day, na_resolve);

    if (na_resolve) {
      na = true;
      return lsec;
    }
  }

  date::local_days out_lday{out_ymd};
  date::local_seconds out_lsec_floor{out_lday};
  date::local_seconds out_lsec{out_lsec_floor + time_of_day};

  return out_lsec;
}

static inline date::local_seconds adjust_month(const date::local_seconds& lsec,
                                               const int& value,
                                               const r_ssize& i,
                                               const enum day_nonexistent& day_nonexistent,
                                               bool& na) {
  check_value_adjust_month(value);

  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  std::chrono::seconds time_of_day = lsec - lsec_floor;

  date::year_month_day ymd{lday};

  unsigned int month = static_cast<unsigned int>(value);

  date::year_month_day out_ymd = ymd.year() / date::month{month} / ymd.day();

  if (!out_ymd.ok()) {
    bool na_resolve = false;

    resolve_day_nonexistent(i, day_nonexistent, out_ymd, time_of_day, na_resolve);

    if (na_resolve) {
      na = true;
      return lsec;
    }
  }

  date::local_days out_lday{out_ymd};
  date::local_seconds out_lsec_floor{out_lday};
  date::local_seconds out_lsec{out_lsec_floor + time_of_day};

  return out_lsec;
}

static inline date::local_seconds adjust_day(const date::local_seconds& lsec,
                                             const int& value,
                                             const r_ssize& i,
                                             const enum day_nonexistent& day_nonexistent,
                                             bool& na) {
  check_value_adjust_day(value);

  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  std::chrono::seconds time_of_day = lsec - lsec_floor;

  date::year_month_day ymd{lday};

  unsigned int day = static_cast<unsigned int>(value);

  date::year_month_day out_ymd = ymd.year() / ymd.month() / date::day{day};

  if (!out_ymd.ok()) {
    bool na_resolve = false;

    resolve_day_nonexistent(i, day_nonexistent, out_ymd, time_of_day, na_resolve);

    if (na_resolve) {
      na = true;
      return lsec;
    }
  }

  date::local_days out_lday{out_ymd};
  date::local_seconds out_lsec_floor{out_lday};
  date::local_seconds out_lsec{out_lsec_floor + time_of_day};

  return out_lsec;
}

static inline date::local_seconds adjust_last_day_of_month(const date::local_seconds& lsec,
                                                           const int& value) {
  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  std::chrono::seconds time_of_day = lsec - lsec_floor;

  date::year_month_day ymd{lday};

  date::year_month_day out_ymd = ymd.year() / ymd.month() / date::last;

  date::local_days out_lday{out_ymd};
  date::local_seconds out_lsec_floor{out_lday};
  date::local_seconds out_lsec{out_lsec_floor + time_of_day};

  return out_lsec;
}

static inline date::local_seconds adjust_switch(const date::local_seconds& lsec,
                                                const int& value,
                                                const r_ssize& i,
                                                const enum day_nonexistent& day_nonexistent,
                                                const enum adjuster& adjuster,
                                                bool& na) {
  switch (adjuster) {
  case adjuster::year: {
    return adjust_year(lsec, value, i, day_nonexistent, na);
  }
  case adjuster::month: {
    return adjust_month(lsec, value, i, day_nonexistent, na);
  }
  case adjuster::day: {
    return adjust_day(lsec, value, i, day_nonexistent, na);
  }
  case adjuster::hour: {
    return adjust_hour(lsec, value);
  }
  case adjuster::minute: {
    return adjust_minute(lsec, value);
  }
  case adjuster::second: {
    return adjust_second(lsec, value);
  }
  case adjuster::last_day_of_month: {
    return adjust_last_day_of_month(lsec, value);
  }
  }
}

// -----------------------------------------------------------------------------

static inline void adjust_local_year(const r_ssize& i, const int& value, int* p_x) {
  check_value_adjust_year(value);
  p_x[i] = value;
}
static inline void adjust_local_month(const r_ssize& i, const int& value, int* p_x) {
  check_value_adjust_month(value);
  p_x[i] = value;
}
static inline void adjust_local_day(const r_ssize& i, const int& value, int* p_x) {
  check_value_adjust_day(value);
  p_x[i] = value;
}
static inline void adjust_local_hour(const r_ssize& i, const int& value, int* p_x) {
  check_value_adjust_hour(value);
  p_x[i] = value;
}
static inline void adjust_local_minute(const r_ssize& i, const int& value, int* p_x) {
  check_value_adjust_minute(value);
  p_x[i] = value;
}
static inline void adjust_local_second(const r_ssize& i, const int& value, int* p_x) {
  check_value_adjust_second(value);
  p_x[i] = value;
}
static inline void adjust_local_last_day_of_month(const r_ssize& i,
                                                  const int* p_year,
                                                  const int* p_month,
                                                  int* p_x) {
  int year = p_year[i];
  unsigned int month = static_cast<unsigned int>(p_month[i]);
  date::year_month_day ymd = date::year{year} / date::month{month} / date::last;
  p_x[i] = static_cast<unsigned int>(ymd.day());
}

static inline void adjust_local_switch(const enum adjuster& adjuster,
                                       const r_ssize& i,
                                       const int& value,
                                       int* p_year,
                                       int* p_month,
                                       int* p_day,
                                       int* p_hour,
                                       int* p_minute,
                                       int* p_second) {
  switch (adjuster) {
  case adjuster::year: {
    return adjust_local_year(i, value, p_year);
  }
  case adjuster::month: {
    return adjust_local_month(i, value, p_month);
  }
  case adjuster::day: {
    return adjust_local_day(i, value, p_day);
  }
  case adjuster::hour: {
    return adjust_local_hour(i, value, p_hour);
  }
  case adjuster::minute: {
    return adjust_local_minute(i, value, p_minute);
  }
  case adjuster::second: {
    return adjust_local_second(i, value, p_second);
  }
  case adjuster::last_day_of_month: {
    return adjust_local_last_day_of_month(i, p_year, p_month, p_day);
  }
  }
}
