// Generated by cpp11: do not edit by hand
// clang-format off

#include "civil_types.h"
#include "cpp11/declarations.hpp"

// adjust.cpp
cpp11::writable::list adjust_gregorian_calendar(const civil_field& calendar, const cpp11::integers& value, const cpp11::strings& day_nonexistent, const cpp11::strings& adjuster);
extern "C" SEXP _civil_adjust_gregorian_calendar(SEXP calendar, SEXP value, SEXP day_nonexistent, SEXP adjuster) {
  BEGIN_CPP11
    return cpp11::as_sexp(adjust_gregorian_calendar(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(value), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(adjuster)));
  END_CPP11
}
// adjust.cpp
civil_writable_rcrd adjust_naive_time_point_seconds_of_day_cpp(const civil_rcrd& x, const cpp11::integers& value, const cpp11::strings& adjuster);
extern "C" SEXP _civil_adjust_naive_time_point_seconds_of_day_cpp(SEXP x, SEXP value, SEXP adjuster) {
  BEGIN_CPP11
    return cpp11::as_sexp(adjust_naive_time_point_seconds_of_day_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_rcrd&>>(x), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(value), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(adjuster)));
  END_CPP11
}
// adjust.cpp
civil_writable_rcrd adjust_naive_time_point_nanoseconds_of_second_cpp(const civil_rcrd& x, const cpp11::integers& value, const cpp11::strings& adjuster);
extern "C" SEXP _civil_adjust_naive_time_point_nanoseconds_of_second_cpp(SEXP x, SEXP value, SEXP adjuster) {
  BEGIN_CPP11
    return cpp11::as_sexp(adjust_naive_time_point_nanoseconds_of_second_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_rcrd&>>(x), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(value), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(adjuster)));
  END_CPP11
}
// adjust.cpp
cpp11::writable::list adjust_quarterly_calendar(const civil_field& calendar, const cpp11::integers& value, const int& start, const cpp11::strings& day_nonexistent, const cpp11::strings& adjuster);
extern "C" SEXP _civil_adjust_quarterly_calendar(SEXP calendar, SEXP value, SEXP start, SEXP day_nonexistent, SEXP adjuster) {
  BEGIN_CPP11
    return cpp11::as_sexp(adjust_quarterly_calendar(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(value), cpp11::as_cpp<cpp11::decay_t<const int&>>(start), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(adjuster)));
  END_CPP11
}
// adjust.cpp
cpp11::writable::list adjust_iso_calendar(const civil_field& calendar, const cpp11::integers& value, const cpp11::strings& day_nonexistent, const cpp11::strings& adjuster);
extern "C" SEXP _civil_adjust_iso_calendar(SEXP calendar, SEXP value, SEXP day_nonexistent, SEXP adjuster) {
  BEGIN_CPP11
    return cpp11::as_sexp(adjust_iso_calendar(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(value), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(adjuster)));
  END_CPP11
}
// adjust.cpp
civil_writable_field downcast_nanoseconds_of_second_precision(const civil_field& nanoseconds_of_second, const cpp11::strings& precision);
extern "C" SEXP _civil_downcast_nanoseconds_of_second_precision(SEXP nanoseconds_of_second, SEXP precision) {
  BEGIN_CPP11
    return cpp11::as_sexp(downcast_nanoseconds_of_second_precision(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(nanoseconds_of_second), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(precision)));
  END_CPP11
}
// arithmetic.cpp
cpp11::writable::list add_gregorian_calendar_years_or_months(const civil_field& calendar, const cpp11::integers& n, const cpp11::strings& day_nonexistent, const cpp11::strings& unit);
extern "C" SEXP _civil_add_gregorian_calendar_years_or_months(SEXP calendar, SEXP n, SEXP day_nonexistent, SEXP unit) {
  BEGIN_CPP11
    return cpp11::as_sexp(add_gregorian_calendar_years_or_months(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(n), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(unit)));
  END_CPP11
}
// arithmetic.cpp
cpp11::writable::list add_calendar_weeks_or_days(const civil_field& calendar, const cpp11::integers& n, const cpp11::strings& unit);
extern "C" SEXP _civil_add_calendar_weeks_or_days(SEXP calendar, SEXP n, SEXP unit) {
  BEGIN_CPP11
    return cpp11::as_sexp(add_calendar_weeks_or_days(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(n), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(unit)));
  END_CPP11
}
// arithmetic.cpp
civil_writable_rcrd add_time_point_seconds_of_day_cpp(const civil_rcrd& x, const cpp11::integers& n, const cpp11::strings& unit);
extern "C" SEXP _civil_add_time_point_seconds_of_day_cpp(SEXP x, SEXP n, SEXP unit) {
  BEGIN_CPP11
    return cpp11::as_sexp(add_time_point_seconds_of_day_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_rcrd&>>(x), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(n), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(unit)));
  END_CPP11
}
// arithmetic.cpp
civil_writable_rcrd add_time_point_nanoseconds_of_second_cpp(const civil_rcrd& x, const cpp11::integers& n, const cpp11::strings& unit);
extern "C" SEXP _civil_add_time_point_nanoseconds_of_second_cpp(SEXP x, SEXP n, SEXP unit) {
  BEGIN_CPP11
    return cpp11::as_sexp(add_time_point_nanoseconds_of_second_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_rcrd&>>(x), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(n), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(unit)));
  END_CPP11
}
// arithmetic.cpp
cpp11::writable::list add_quarterly_calendar_years_or_quarters(const civil_field& calendar, const cpp11::integers& n, const int& start, const cpp11::strings& day_nonexistent, const cpp11::strings& unit);
extern "C" SEXP _civil_add_quarterly_calendar_years_or_quarters(SEXP calendar, SEXP n, SEXP start, SEXP day_nonexistent, SEXP unit) {
  BEGIN_CPP11
    return cpp11::as_sexp(add_quarterly_calendar_years_or_quarters(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(n), cpp11::as_cpp<cpp11::decay_t<const int&>>(start), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(unit)));
  END_CPP11
}
// arithmetic.cpp
cpp11::writable::list add_iso_calendar_years(const civil_field& calendar, const cpp11::integers& n, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_add_iso_calendar_years(SEXP calendar, SEXP n, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(add_iso_calendar_years(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(n), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_zoned_seconds_to_naive_second_point_fields(const cpp11::doubles& seconds, const cpp11::strings& zone);
extern "C" SEXP _civil_convert_zoned_seconds_to_naive_second_point_fields(SEXP seconds, SEXP zone) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_zoned_seconds_to_naive_second_point_fields(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles&>>(seconds), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone)));
  END_CPP11
}
// converters.cpp
cpp11::writable::doubles convert_naive_second_point_fields_to_zoned_seconds_cpp(const civil_field& calendar, const civil_field& seconds_of_day, const cpp11::strings& zone, const cpp11::strings& dst_nonexistent, const cpp11::strings& dst_ambiguous, const cpp11::integers& size);
extern "C" SEXP _civil_convert_naive_second_point_fields_to_zoned_seconds_cpp(SEXP calendar, SEXP seconds_of_day, SEXP zone, SEXP dst_nonexistent, SEXP dst_ambiguous, SEXP size) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_naive_second_point_fields_to_zoned_seconds_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_ambiguous), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(size)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_year_month_day_hour_minute_second_to_naive_second_point_fields(const cpp11::integers& year, const cpp11::integers& month, const cpp11::integers& day, const cpp11::integers& hour, const cpp11::integers& minute, const cpp11::integers& second, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_convert_year_month_day_hour_minute_second_to_naive_second_point_fields(SEXP year, SEXP month, SEXP day, SEXP hour, SEXP minute, SEXP second, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_year_month_day_hour_minute_second_to_naive_second_point_fields(cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(year), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(month), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(day), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(hour), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(minute), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(second), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_year_month_day_hour_minute_second_nanosecond_to_naive_subsecond_point_fields(const cpp11::integers& year, const cpp11::integers& month, const cpp11::integers& day, const cpp11::integers& hour, const cpp11::integers& minute, const cpp11::integers& second, const cpp11::integers& nanosecond, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_convert_year_month_day_hour_minute_second_nanosecond_to_naive_subsecond_point_fields(SEXP year, SEXP month, SEXP day, SEXP hour, SEXP minute, SEXP second, SEXP nanosecond, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_year_month_day_hour_minute_second_nanosecond_to_naive_subsecond_point_fields(cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(year), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(month), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(day), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(hour), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(minute), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(second), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(nanosecond), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// converters.cpp
civil_writable_list_of_integers convert_calendar_days_to_year_month_day(const civil_field& calendar);
extern "C" SEXP _civil_convert_calendar_days_to_year_month_day(SEXP calendar) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_calendar_days_to_year_month_day(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_second_point_fields_from_zoned_to_naive(const civil_field& calendar, const civil_field& seconds_of_day, const cpp11::strings& zone);
extern "C" SEXP _civil_convert_second_point_fields_from_zoned_to_naive(SEXP calendar, SEXP seconds_of_day, SEXP zone) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_second_point_fields_from_zoned_to_naive(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_zoned_seconds_to_zoned_second_point_fields(const cpp11::doubles& seconds);
extern "C" SEXP _civil_convert_zoned_seconds_to_zoned_second_point_fields(SEXP seconds) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_zoned_seconds_to_zoned_second_point_fields(cpp11::as_cpp<cpp11::decay_t<const cpp11::doubles&>>(seconds)));
  END_CPP11
}
// converters.cpp
civil_writable_field convert_year_quarternum_quarterday_to_calendar_days(const cpp11::integers& year, const cpp11::integers& quarternum, const cpp11::integers& quarterday, int start, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_convert_year_quarternum_quarterday_to_calendar_days(SEXP year, SEXP quarternum, SEXP quarterday, SEXP start, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_year_quarternum_quarterday_to_calendar_days(cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(year), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(quarternum), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(quarterday), cpp11::as_cpp<cpp11::decay_t<int>>(start), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// converters.cpp
cpp11::writable::list_of<cpp11::writable::integers> convert_calendar_days_to_year_quarternum_quarterday(const civil_field& calendar, int start);
extern "C" SEXP _civil_convert_calendar_days_to_year_quarternum_quarterday(SEXP calendar, SEXP start) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_calendar_days_to_year_quarternum_quarterday(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<int>>(start)));
  END_CPP11
}
// converters.cpp
civil_writable_field convert_iso_year_weeknum_weekday_to_calendar_days(const cpp11::integers& year, const cpp11::integers& weeknum, const cpp11::integers& weekday, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_convert_iso_year_weeknum_weekday_to_calendar_days(SEXP year, SEXP weeknum, SEXP weekday, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_iso_year_weeknum_weekday_to_calendar_days(cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(year), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(weeknum), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(weekday), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// converters.cpp
cpp11::writable::list_of<cpp11::writable::integers> convert_calendar_days_to_iso_year_weeknum_weekday(const civil_field& calendar);
extern "C" SEXP _civil_convert_calendar_days_to_iso_year_weeknum_weekday(SEXP calendar) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_calendar_days_to_iso_year_weeknum_weekday(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar)));
  END_CPP11
}
// converters.cpp
civil_writable_field convert_year_month_day_to_calendar_days(const cpp11::integers& year, const cpp11::integers& month, const cpp11::integers& day, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_convert_year_month_day_to_calendar_days(SEXP year, SEXP month, SEXP day, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_year_month_day_to_calendar_days(cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(year), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(month), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(day), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_calendar_days_hour_minute_second_to_naive_second_point_fields(const civil_field& calendar, const cpp11::integers& hour, const cpp11::integers& minute, const cpp11::integers& second);
extern "C" SEXP _civil_convert_calendar_days_hour_minute_second_to_naive_second_point_fields(SEXP calendar, SEXP hour, SEXP minute, SEXP second) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_calendar_days_hour_minute_second_to_naive_second_point_fields(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(hour), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(minute), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(second)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_calendar_days_hour_minute_second_subsecond_to_naive_subsecond_point_fields(const civil_field& calendar, const cpp11::integers& hour, const cpp11::integers& minute, const cpp11::integers& second, const cpp11::integers& subsecond, const cpp11::strings& precision);
extern "C" SEXP _civil_convert_calendar_days_hour_minute_second_subsecond_to_naive_subsecond_point_fields(SEXP calendar, SEXP hour, SEXP minute, SEXP second, SEXP subsecond, SEXP precision) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_calendar_days_hour_minute_second_subsecond_to_naive_subsecond_point_fields(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(hour), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(minute), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(second), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(subsecond), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(precision)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_second_point_fields_from_naive_to_zoned_cpp(const civil_field& calendar, const civil_field& seconds_of_day, const cpp11::strings& zone, const cpp11::strings& dst_nonexistent, const cpp11::strings& dst_ambiguous);
extern "C" SEXP _civil_convert_second_point_fields_from_naive_to_zoned_cpp(SEXP calendar, SEXP seconds_of_day, SEXP zone, SEXP dst_nonexistent, SEXP dst_ambiguous) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_second_point_fields_from_naive_to_zoned_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_ambiguous)));
  END_CPP11
}
// converters.cpp
civil_writable_rcrd convert_subsecond_point_fields_from_naive_to_zoned_cpp(const civil_field& calendar, const civil_field& seconds_of_day, const civil_field& nanoseconds_of_second, const cpp11::strings& precision, const cpp11::strings& zone, const cpp11::strings& dst_nonexistent, const cpp11::strings& dst_ambiguous);
extern "C" SEXP _civil_convert_subsecond_point_fields_from_naive_to_zoned_cpp(SEXP calendar, SEXP seconds_of_day, SEXP nanoseconds_of_second, SEXP precision, SEXP zone, SEXP dst_nonexistent, SEXP dst_ambiguous) {
  BEGIN_CPP11
    return cpp11::as_sexp(convert_subsecond_point_fields_from_naive_to_zoned_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(nanoseconds_of_second), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(precision), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_ambiguous)));
  END_CPP11
}
// floor.cpp
civil_writable_field floor_calendar_days_to_year_month_precision(const civil_field& calendar);
extern "C" SEXP _civil_floor_calendar_days_to_year_month_precision(SEXP calendar) {
  BEGIN_CPP11
    return cpp11::as_sexp(floor_calendar_days_to_year_month_precision(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar)));
  END_CPP11
}
// floor.cpp
civil_writable_field floor_calendar_days_to_year_quarternum_precision(const civil_field& calendar, int start);
extern "C" SEXP _civil_floor_calendar_days_to_year_quarternum_precision(SEXP calendar, SEXP start) {
  BEGIN_CPP11
    return cpp11::as_sexp(floor_calendar_days_to_year_quarternum_precision(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<int>>(start)));
  END_CPP11
}
// floor.cpp
civil_writable_field floor_calendar_days_to_iso_year_weeknum_precision(const civil_field& calendar);
extern "C" SEXP _civil_floor_calendar_days_to_iso_year_weeknum_precision(SEXP calendar) {
  BEGIN_CPP11
    return cpp11::as_sexp(floor_calendar_days_to_iso_year_weeknum_precision(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar)));
  END_CPP11
}
// format.cpp
cpp11::writable::strings format_time_point(const civil_field& calendar, const civil_field& seconds_of_day, const civil_field& nanoseconds_of_second, const cpp11::strings& zone, const cpp11::strings& format, const cpp11::strings& precision, const bool& naive, const bool& abbreviate_zone);
extern "C" SEXP _civil_format_time_point(SEXP calendar, SEXP seconds_of_day, SEXP nanoseconds_of_second, SEXP zone, SEXP format, SEXP precision, SEXP naive, SEXP abbreviate_zone) {
  BEGIN_CPP11
    return cpp11::as_sexp(format_time_point(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(nanoseconds_of_second), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(format), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(precision), cpp11::as_cpp<cpp11::decay_t<const bool&>>(naive), cpp11::as_cpp<cpp11::decay_t<const bool&>>(abbreviate_zone)));
  END_CPP11
}
// getters.cpp
cpp11::writable::integers get_offset_cpp(const civil_field& calendar, const civil_field& seconds_of_day, const cpp11::strings& zone);
extern "C" SEXP _civil_get_offset_cpp(SEXP calendar, SEXP seconds_of_day, SEXP zone) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_offset_cpp(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(calendar), cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone)));
  END_CPP11
}
// install.cpp
void clock_set_install(const cpp11::strings& path);
extern "C" SEXP _civil_clock_set_install(SEXP path) {
  BEGIN_CPP11
    clock_set_install(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(path));
    return R_NilValue;
  END_CPP11
}
// parse.cpp
civil_writable_rcrd parse_zoned_datetime_cpp(const cpp11::strings& x, const cpp11::strings& format, const cpp11::strings& zone, const cpp11::strings& dst_nonexistent, const cpp11::strings& dst_ambiguous, const cpp11::integers& size);
extern "C" SEXP _civil_parse_zoned_datetime_cpp(SEXP x, SEXP format, SEXP zone, SEXP dst_nonexistent, SEXP dst_ambiguous, SEXP size) {
  BEGIN_CPP11
    return cpp11::as_sexp(parse_zoned_datetime_cpp(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(x), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(format), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(dst_ambiguous), cpp11::as_cpp<cpp11::decay_t<const cpp11::integers&>>(size)));
  END_CPP11
}
// parse.cpp
civil_writable_rcrd parse_naive_datetime_cpp(const cpp11::strings& x, const cpp11::strings& format);
extern "C" SEXP _civil_parse_naive_datetime_cpp(SEXP x, SEXP format) {
  BEGIN_CPP11
    return cpp11::as_sexp(parse_naive_datetime_cpp(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(x), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(format)));
  END_CPP11
}
// resolve.cpp
civil_writable_field resolve_seconds_of_day(const civil_field& seconds_of_day, const cpp11::logicals& ok, const cpp11::strings& day_nonexistent);
extern "C" SEXP _civil_resolve_seconds_of_day(SEXP seconds_of_day, SEXP ok, SEXP day_nonexistent) {
  BEGIN_CPP11
    return cpp11::as_sexp(resolve_seconds_of_day(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(seconds_of_day), cpp11::as_cpp<cpp11::decay_t<const cpp11::logicals&>>(ok), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent)));
  END_CPP11
}
// resolve.cpp
civil_writable_field resolve_nanoseconds_of_second(const civil_field& nanoseconds_of_second, const cpp11::logicals& ok, const cpp11::strings& day_nonexistent, const cpp11::strings& precision);
extern "C" SEXP _civil_resolve_nanoseconds_of_second(SEXP nanoseconds_of_second, SEXP ok, SEXP day_nonexistent, SEXP precision) {
  BEGIN_CPP11
    return cpp11::as_sexp(resolve_nanoseconds_of_second(cpp11::as_cpp<cpp11::decay_t<const civil_field&>>(nanoseconds_of_second), cpp11::as_cpp<cpp11::decay_t<const cpp11::logicals&>>(ok), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(day_nonexistent), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(precision)));
  END_CPP11
}
// zone.cpp
cpp11::writable::strings zone_standardize(const cpp11::strings& zone);
extern "C" SEXP _civil_zone_standardize(SEXP zone) {
  BEGIN_CPP11
    return cpp11::as_sexp(zone_standardize(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone)));
  END_CPP11
}
// zone.cpp
cpp11::writable::logicals zone_is_valid(const cpp11::strings& zone);
extern "C" SEXP _civil_zone_is_valid(SEXP zone) {
  BEGIN_CPP11
    return cpp11::as_sexp(zone_is_valid(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(zone)));
  END_CPP11
}
// zone.cpp
cpp11::writable::strings zone_current();
extern "C" SEXP _civil_zone_current() {
  BEGIN_CPP11
    return cpp11::as_sexp(zone_current());
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _civil_add_calendar_weeks_or_days(SEXP, SEXP, SEXP);
extern SEXP _civil_add_gregorian_calendar_years_or_months(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_add_iso_calendar_years(SEXP, SEXP, SEXP);
extern SEXP _civil_add_quarterly_calendar_years_or_quarters(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_add_time_point_nanoseconds_of_second_cpp(SEXP, SEXP, SEXP);
extern SEXP _civil_add_time_point_seconds_of_day_cpp(SEXP, SEXP, SEXP);
extern SEXP _civil_adjust_gregorian_calendar(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_adjust_iso_calendar(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_adjust_naive_time_point_nanoseconds_of_second_cpp(SEXP, SEXP, SEXP);
extern SEXP _civil_adjust_naive_time_point_seconds_of_day_cpp(SEXP, SEXP, SEXP);
extern SEXP _civil_adjust_quarterly_calendar(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_clock_set_install(SEXP);
extern SEXP _civil_convert_calendar_days_hour_minute_second_subsecond_to_naive_subsecond_point_fields(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_calendar_days_hour_minute_second_to_naive_second_point_fields(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_calendar_days_to_iso_year_weeknum_weekday(SEXP);
extern SEXP _civil_convert_calendar_days_to_year_month_day(SEXP);
extern SEXP _civil_convert_calendar_days_to_year_quarternum_quarterday(SEXP, SEXP);
extern SEXP _civil_convert_iso_year_weeknum_weekday_to_calendar_days(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_naive_second_point_fields_to_zoned_seconds_cpp(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_second_point_fields_from_naive_to_zoned_cpp(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_second_point_fields_from_zoned_to_naive(SEXP, SEXP, SEXP);
extern SEXP _civil_convert_subsecond_point_fields_from_naive_to_zoned_cpp(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_year_month_day_hour_minute_second_nanosecond_to_naive_subsecond_point_fields(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_year_month_day_hour_minute_second_to_naive_second_point_fields(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_year_month_day_to_calendar_days(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_year_quarternum_quarterday_to_calendar_days(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_convert_zoned_seconds_to_naive_second_point_fields(SEXP, SEXP);
extern SEXP _civil_convert_zoned_seconds_to_zoned_second_point_fields(SEXP);
extern SEXP _civil_downcast_nanoseconds_of_second_precision(SEXP, SEXP);
extern SEXP _civil_floor_calendar_days_to_iso_year_weeknum_precision(SEXP);
extern SEXP _civil_floor_calendar_days_to_year_month_precision(SEXP);
extern SEXP _civil_floor_calendar_days_to_year_quarternum_precision(SEXP, SEXP);
extern SEXP _civil_format_time_point(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_get_offset_cpp(SEXP, SEXP, SEXP);
extern SEXP _civil_parse_naive_datetime_cpp(SEXP, SEXP);
extern SEXP _civil_parse_zoned_datetime_cpp(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_resolve_nanoseconds_of_second(SEXP, SEXP, SEXP, SEXP);
extern SEXP _civil_resolve_seconds_of_day(SEXP, SEXP, SEXP);
extern SEXP _civil_zone_current();
extern SEXP _civil_zone_is_valid(SEXP);
extern SEXP _civil_zone_standardize(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_civil_add_calendar_weeks_or_days",                                                           (DL_FUNC) &_civil_add_calendar_weeks_or_days,                                                           3},
    {"_civil_add_gregorian_calendar_years_or_months",                                               (DL_FUNC) &_civil_add_gregorian_calendar_years_or_months,                                               4},
    {"_civil_add_iso_calendar_years",                                                               (DL_FUNC) &_civil_add_iso_calendar_years,                                                               3},
    {"_civil_add_quarterly_calendar_years_or_quarters",                                             (DL_FUNC) &_civil_add_quarterly_calendar_years_or_quarters,                                             5},
    {"_civil_add_time_point_nanoseconds_of_second_cpp",                                             (DL_FUNC) &_civil_add_time_point_nanoseconds_of_second_cpp,                                             3},
    {"_civil_add_time_point_seconds_of_day_cpp",                                                    (DL_FUNC) &_civil_add_time_point_seconds_of_day_cpp,                                                    3},
    {"_civil_adjust_gregorian_calendar",                                                            (DL_FUNC) &_civil_adjust_gregorian_calendar,                                                            4},
    {"_civil_adjust_iso_calendar",                                                                  (DL_FUNC) &_civil_adjust_iso_calendar,                                                                  4},
    {"_civil_adjust_naive_time_point_nanoseconds_of_second_cpp",                                    (DL_FUNC) &_civil_adjust_naive_time_point_nanoseconds_of_second_cpp,                                    3},
    {"_civil_adjust_naive_time_point_seconds_of_day_cpp",                                           (DL_FUNC) &_civil_adjust_naive_time_point_seconds_of_day_cpp,                                           3},
    {"_civil_adjust_quarterly_calendar",                                                            (DL_FUNC) &_civil_adjust_quarterly_calendar,                                                            5},
    {"_civil_clock_set_install",                                                                    (DL_FUNC) &_civil_clock_set_install,                                                                    1},
    {"_civil_convert_calendar_days_hour_minute_second_subsecond_to_naive_subsecond_point_fields",   (DL_FUNC) &_civil_convert_calendar_days_hour_minute_second_subsecond_to_naive_subsecond_point_fields,   6},
    {"_civil_convert_calendar_days_hour_minute_second_to_naive_second_point_fields",                (DL_FUNC) &_civil_convert_calendar_days_hour_minute_second_to_naive_second_point_fields,                4},
    {"_civil_convert_calendar_days_to_iso_year_weeknum_weekday",                                    (DL_FUNC) &_civil_convert_calendar_days_to_iso_year_weeknum_weekday,                                    1},
    {"_civil_convert_calendar_days_to_year_month_day",                                              (DL_FUNC) &_civil_convert_calendar_days_to_year_month_day,                                              1},
    {"_civil_convert_calendar_days_to_year_quarternum_quarterday",                                  (DL_FUNC) &_civil_convert_calendar_days_to_year_quarternum_quarterday,                                  2},
    {"_civil_convert_iso_year_weeknum_weekday_to_calendar_days",                                    (DL_FUNC) &_civil_convert_iso_year_weeknum_weekday_to_calendar_days,                                    4},
    {"_civil_convert_naive_second_point_fields_to_zoned_seconds_cpp",                               (DL_FUNC) &_civil_convert_naive_second_point_fields_to_zoned_seconds_cpp,                               6},
    {"_civil_convert_second_point_fields_from_naive_to_zoned_cpp",                                  (DL_FUNC) &_civil_convert_second_point_fields_from_naive_to_zoned_cpp,                                  5},
    {"_civil_convert_second_point_fields_from_zoned_to_naive",                                      (DL_FUNC) &_civil_convert_second_point_fields_from_zoned_to_naive,                                      3},
    {"_civil_convert_subsecond_point_fields_from_naive_to_zoned_cpp",                               (DL_FUNC) &_civil_convert_subsecond_point_fields_from_naive_to_zoned_cpp,                               7},
    {"_civil_convert_year_month_day_hour_minute_second_nanosecond_to_naive_subsecond_point_fields", (DL_FUNC) &_civil_convert_year_month_day_hour_minute_second_nanosecond_to_naive_subsecond_point_fields, 8},
    {"_civil_convert_year_month_day_hour_minute_second_to_naive_second_point_fields",               (DL_FUNC) &_civil_convert_year_month_day_hour_minute_second_to_naive_second_point_fields,               7},
    {"_civil_convert_year_month_day_to_calendar_days",                                              (DL_FUNC) &_civil_convert_year_month_day_to_calendar_days,                                              4},
    {"_civil_convert_year_quarternum_quarterday_to_calendar_days",                                  (DL_FUNC) &_civil_convert_year_quarternum_quarterday_to_calendar_days,                                  5},
    {"_civil_convert_zoned_seconds_to_naive_second_point_fields",                                   (DL_FUNC) &_civil_convert_zoned_seconds_to_naive_second_point_fields,                                   2},
    {"_civil_convert_zoned_seconds_to_zoned_second_point_fields",                                   (DL_FUNC) &_civil_convert_zoned_seconds_to_zoned_second_point_fields,                                   1},
    {"_civil_downcast_nanoseconds_of_second_precision",                                             (DL_FUNC) &_civil_downcast_nanoseconds_of_second_precision,                                             2},
    {"_civil_floor_calendar_days_to_iso_year_weeknum_precision",                                    (DL_FUNC) &_civil_floor_calendar_days_to_iso_year_weeknum_precision,                                    1},
    {"_civil_floor_calendar_days_to_year_month_precision",                                          (DL_FUNC) &_civil_floor_calendar_days_to_year_month_precision,                                          1},
    {"_civil_floor_calendar_days_to_year_quarternum_precision",                                     (DL_FUNC) &_civil_floor_calendar_days_to_year_quarternum_precision,                                     2},
    {"_civil_format_time_point",                                                                    (DL_FUNC) &_civil_format_time_point,                                                                    8},
    {"_civil_get_offset_cpp",                                                                       (DL_FUNC) &_civil_get_offset_cpp,                                                                       3},
    {"_civil_parse_naive_datetime_cpp",                                                             (DL_FUNC) &_civil_parse_naive_datetime_cpp,                                                             2},
    {"_civil_parse_zoned_datetime_cpp",                                                             (DL_FUNC) &_civil_parse_zoned_datetime_cpp,                                                             6},
    {"_civil_resolve_nanoseconds_of_second",                                                        (DL_FUNC) &_civil_resolve_nanoseconds_of_second,                                                        4},
    {"_civil_resolve_seconds_of_day",                                                               (DL_FUNC) &_civil_resolve_seconds_of_day,                                                               3},
    {"_civil_zone_current",                                                                         (DL_FUNC) &_civil_zone_current,                                                                         0},
    {"_civil_zone_is_valid",                                                                        (DL_FUNC) &_civil_zone_is_valid,                                                                        1},
    {"_civil_zone_standardize",                                                                     (DL_FUNC) &_civil_zone_standardize,                                                                     1},
    {NULL, NULL, 0}
};
}

extern "C" void R_init_civil(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
