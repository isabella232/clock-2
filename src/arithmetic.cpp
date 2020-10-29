#include "r.h"
#include "utils.h"
#include "zone.h"
#include "enums.h"
#include "conversion.h"
#include "resolve.h"
#include <date/date.h>
#include <date/tz.h>

// -----------------------------------------------------------------------------

static date::local_seconds add_year_month_local_one(const date::local_seconds& lsec,
                                                    int n,
                                                    r_ssize i,
                                                    const enum day_nonexistant& day_nonexistant,
                                                    const enum unit& unit);

// -----------------------------------------------------------------------------


static sexp add_period_posixct_impl(sexp x,
                                    sexp n,
                                    enum day_nonexistant day_nonexistant,
                                    enum dst_nonexistant dst_nonexistant,
                                    enum dst_ambiguous dst_ambiguous,
                                    r_ssize size,
                                    enum unit unit);

[[cpp11::register]]
SEXP add_period_posixct_cpp(SEXP x,
                            SEXP n,
                            SEXP day_resolver,
                            SEXP dst_resolver,
                            SEXP size,
                            SEXP unit) {
  sexp day_nonexistant = r_list_get(day_resolver, 0);
  sexp dst_nonexistant = r_list_get(dst_resolver, 0);
  sexp dst_ambiguous = r_list_get(dst_resolver, 1);

  enum day_nonexistant c_day_nonexistant = parse_day_nonexistant(day_nonexistant);
  enum dst_nonexistant c_dst_nonexistant = parse_dst_nonexistant_arithmetic(dst_nonexistant);
  enum dst_ambiguous c_dst_ambiguous = parse_dst_ambiguous_arithmetic(dst_ambiguous);

  r_ssize c_size = r_int_get(size, 0);

  enum unit c_unit = parse_unit(unit);

  return add_period_posixct_impl(
    x,
    n,
    c_day_nonexistant,
    c_dst_nonexistant,
    c_dst_ambiguous,
    c_size,
    c_unit
  );
}

static sexp add_year_month_posixct(sexp x,
                                   sexp n,
                                   enum day_nonexistant day_nonexistant,
                                   enum dst_nonexistant dst_nonexistant,
                                   enum dst_ambiguous dst_ambiguous,
                                   r_ssize size,
                                   enum unit unit);

static sexp add_period_posixct_impl(sexp x,
                                    sexp n,
                                    enum day_nonexistant day_nonexistant,
                                    enum dst_nonexistant dst_nonexistant,
                                    enum dst_ambiguous dst_ambiguous,
                                    r_ssize size,
                                    enum unit unit) {
  switch (unit) {
  case unit::year:
  case unit::month: {
    return add_year_month_posixct(
      x,
      n,
      day_nonexistant,
      dst_nonexistant,
      dst_ambiguous,
      size,
      unit
    );
  }
  case unit::week:
  case unit::day:
  case unit::hour:
  case unit::minute:
  case unit::second: {
    r_abort("not yet supported");
  }
  }
}

// -----------------------------------------------------------------------------

static sexp add_year_month_posixct(sexp x,
                                   sexp n,
                                   enum day_nonexistant day_nonexistant,
                                   enum dst_nonexistant dst_nonexistant,
                                   enum dst_ambiguous dst_ambiguous,
                                   r_ssize size,
                                   enum unit unit) {
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
  const int* p_n = r_int_deref_const(n);

  const bool recycle_x = r_is_scalar(x);
  const bool recycle_n = r_is_scalar(n);

  for (r_ssize i = 0; i < size; ++i) {
    double elt_x = recycle_x ? p_x[0] : p_x[i];
    int elt_n = recycle_n ? p_n[0] : p_n[i];

    int64_t elt = as_int64(elt_x);

    if (elt == r_int64_na) {
      p_out[i] = r_dbl_na;
      continue;
    }

    if (elt_n == NA_INTEGER) {
      p_out[i] = r_dbl_na;
      continue;
    }

    std::chrono::seconds elt_sec{elt};
    date::sys_seconds elt_ssec{elt_sec};
    date::zoned_seconds elt_zsec = date::make_zoned(p_zone, elt_ssec);
    date::local_seconds elt_lsec = elt_zsec.get_local_time();

    date::local_seconds out_lsec = add_year_month_local_one(
      elt_lsec,
      elt_n,
      i,
      day_nonexistant,
      unit
    );

    if (is_na_lsec(elt_lsec)) {
      p_out[i] = NA_REAL;
      continue;
    }

    const enum dst_direction dst_direction =
      elt_n >= 0 ?
      dst_direction::positive :
      dst_direction::negative;

    p_out[i] = convert_local_seconds_to_posixt(
      out_lsec,
      p_zone,
      i,
      dst_direction,
      dst_nonexistant,
      dst_ambiguous
    );
  }

  UNPROTECT(2);
  return out;
}

// -----------------------------------------------------------------------------

static sexp add_period_local_impl(sexp x,
                                  sexp n,
                                  enum day_nonexistant day_nonexistant,
                                  r_ssize size,
                                  enum unit unit);

[[cpp11::register]]
SEXP add_period_local_cpp(SEXP x,
                          SEXP n,
                          SEXP day_resolver,
                          SEXP size,
                          SEXP unit) {
  sexp day_nonexistant = r_list_get(day_resolver, 0);

  enum day_nonexistant c_day_nonexistant = parse_day_nonexistant(day_nonexistant);

  r_ssize c_size = r_int_get(size, 0);

  enum unit c_unit = parse_unit(unit);

  return add_period_local_impl(
    x,
    n,
    c_day_nonexistant,
    c_size,
    c_unit
  );
}

static sexp add_year_month_local(sexp x,
                                 sexp n,
                                 enum day_nonexistant day_nonexistant,
                                 r_ssize size,
                                 enum unit unit);

static sexp add_period_local_impl(sexp x,
                                  sexp n,
                                  enum day_nonexistant day_nonexistant,
                                  r_ssize size,
                                  enum unit unit) {
  switch (unit) {
  case unit::year:
  case unit::month: {
    return add_year_month_local(
      x,
      n,
      day_nonexistant,
      size,
      unit
    );
  }
  case unit::week:
  case unit::day:
  case unit::hour:
  case unit::minute:
  case unit::second: {
    r_abort("not yet supported");
  }
  }
}

// -----------------------------------------------------------------------------

static sexp add_year_month_local(sexp x,
                                 sexp n,
                                 enum day_nonexistant day_nonexistant,
                                 r_ssize size,
                                 enum unit unit) {
  sexp out = PROTECT(r_new_double(size));
  double* p_out = r_dbl_deref(out);

  r_poke_names(out, r_get_names(x));

  const double* p_x = r_dbl_deref_const(x);
  const int* p_n = r_int_deref_const(n);

  const bool recycle_x = r_is_scalar(x);
  const bool recycle_n = r_is_scalar(n);

  for (r_ssize i = 0; i < size; ++i) {
    double elt_x = recycle_x ? p_x[0] : p_x[i];
    int elt_n = recycle_n ? p_n[0] : p_n[i];

    int64_t elt = as_int64(elt_x);

    if (elt == r_int64_na) {
      p_out[i] = r_dbl_na;
      continue;
    }

    if (elt_n == NA_INTEGER) {
      p_out[i] = r_dbl_na;
      continue;
    }

    std::chrono::seconds elt_sec{elt};
    date::local_seconds elt_lsec{elt_sec};

    date::local_seconds out_lsec = add_year_month_local_one(
      elt_lsec,
      elt_n,
      i,
      day_nonexistant,
      unit
    );

    if (is_na_lsec(elt_lsec)) {
      p_out[i] = NA_REAL;
    } else {
      p_out[i] = out_lsec.time_since_epoch().count();
    }
  }

  UNPROTECT(1);
  return out;
}

// -----------------------------------------------------------------------------

static date::local_seconds add_year_month_local_one(const date::local_seconds& lsec,
                                                    int n,
                                                    r_ssize i,
                                                    const enum day_nonexistant& day_nonexistant,
                                                    const enum unit& unit) {
  date::local_days lday = date::floor<date::days>(lsec);
  date::local_seconds lsec_floor = lday;

  std::chrono::seconds time_of_day = lsec - lsec_floor;

  date::year_month_day ymd{lday};

  date::year_month_day out_ymd;

  if (unit == unit::year) {
    out_ymd = ymd + date::years{n};
  } else {
    out_ymd = ymd + date::months{n};
  }

  if (!out_ymd.ok()) {
    resolve_day_nonexistant(i, day_nonexistant, out_ymd, time_of_day);

    if (is_na_ymd(out_ymd)) {
      return na_lsec();
    }
  }

  date::local_days out_lday{out_ymd};
  date::local_seconds out_lsec_floor{out_lday};
  date::local_seconds out_lsec{out_lsec_floor + time_of_day};

  return out_lsec;
}


