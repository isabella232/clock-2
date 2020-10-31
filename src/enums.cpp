#include "enums.h"
#include "utils.h"
#include <cstring>
#include <string>

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum day_nonexistent parse_day_nonexistent(sexp x) {
  if (!r_is_string(x)) {
    r_abort("`day_nonexistent` must be a string with length 1.");
  }

  const char* string = CHAR(STRING_ELT(x, 0));

  if (!strcmp(string, "last-time")) return day_nonexistent::last_time;
  if (!strcmp(string, "first-time")) return day_nonexistent::first_time;
  if (!strcmp(string, "last-day")) return day_nonexistent::last_day;
  if (!strcmp(string, "first-day")) return day_nonexistent::first_day;
  if (!strcmp(string, "NA")) return day_nonexistent::na;
  if (!strcmp(string, "error")) return day_nonexistent::error;

  r_abort("'%s' is not a recognized `day_nonexistent` option.", string);
}

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum dst_nonexistent parse_dst_nonexistent(sexp x) {
  enum dst_nonexistent out = parse_dst_nonexistent_arithmetic(x);

  if (out == dst_nonexistent::directional) {
    r_abort("Internal error: 'directional' is not allowed for `dst_nonexistent` here.");
  }
  if (out == dst_nonexistent::directional_shift) {
    r_abort("Internal error: 'directional-shift' is not allowed for `dst_nonexistent` here.");
  }

  return out;
}

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum dst_nonexistent parse_dst_nonexistent_arithmetic(sexp x) {
  if (!r_is_string(x)) {
    r_abort("`dst_nonexistent` must be a string with length 1.");
  }

  const char* string = CHAR(STRING_ELT(x, 0));

  if (!strcmp(string, "directional")) return dst_nonexistent::directional;
  if (!strcmp(string, "next")) return dst_nonexistent::next;
  if (!strcmp(string, "previous")) return dst_nonexistent::previous;
  if (!strcmp(string, "directional-shift")) return dst_nonexistent::directional_shift;
  if (!strcmp(string, "next-shift")) return dst_nonexistent::next_shift;
  if (!strcmp(string, "previous-shift")) return dst_nonexistent::previous_shift;
  if (!strcmp(string, "NA")) return dst_nonexistent::na;
  if (!strcmp(string, "error")) return dst_nonexistent::error;

  r_abort("'%s' is not a recognized `dst_nonexistent` option.", string);
}

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum dst_ambiguous parse_dst_ambiguous(sexp x) {
  enum dst_ambiguous out = parse_dst_ambiguous_arithmetic(x);

  if (out == dst_ambiguous::directional) {
    r_abort("'directional' is not allowed for `dst_ambiguous` here.");
  }

  return out;
}

// [[ include("enums.h") ]]
enum dst_ambiguous parse_dst_ambiguous_arithmetic(sexp x) {
  if (!r_is_string(x)) {
    r_abort("`dst_ambiguous` must be a string with length 1.");
  }

  const char* string = CHAR(STRING_ELT(x, 0));

  if (!strcmp(string, "directional")) return dst_ambiguous::directional;
  if (!strcmp(string, "earliest")) return dst_ambiguous::earliest;
  if (!strcmp(string, "latest")) return dst_ambiguous::latest;
  if (!strcmp(string, "NA")) return dst_ambiguous::na;
  if (!strcmp(string, "error")) return dst_ambiguous::error;

  r_abort("'%s' is not a recognized `dst_ambiguous` option.", string);
}

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum unit parse_unit(sexp x) {
  if (!r_is_string(x)) {
    r_abort("`unit` must be a string with length 1.");
  }

  const char* string = CHAR(STRING_ELT(x, 0));

  if (!strcmp(string, "year")) return unit::year;
  if (!strcmp(string, "month")) return unit::month;
  if (!strcmp(string, "week")) return unit::week;
  if (!strcmp(string, "day")) return unit::day;
  if (!strcmp(string, "hour")) return unit::hour;
  if (!strcmp(string, "minute")) return unit::minute;
  if (!strcmp(string, "second")) return unit::second;

  r_abort("'%s' is not a recognized `unit` option.", string);
}

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum update_unit parse_update_unit(sexp x) {
  if (!r_is_string(x)) {
    r_abort("`unit` must be a string with length 1.");
  }

  const char* string = CHAR(STRING_ELT(x, 0));

  if (!strcmp(string, "year")) return update_unit::year;
  if (!strcmp(string, "month")) return update_unit::month;
  if (!strcmp(string, "yday")) return update_unit::yday;
  if (!strcmp(string, "day")) return update_unit::day;
  if (!strcmp(string, "hour")) return update_unit::hour;
  if (!strcmp(string, "minute")) return update_unit::minute;
  if (!strcmp(string, "second")) return update_unit::second;

  r_abort("'%s' is not a recognized `unit` option.", string);
}

// -----------------------------------------------------------------------------

// [[ include("enums.h") ]]
enum adjuster parse_adjuster(sexp x) {
  if (!r_is_string(x)) {
    r_abort("`adjuster` must be a string with length 1.");
  }

  const char* string = CHAR(STRING_ELT(x, 0));

  if (!strcmp(string, "year")) return adjuster::year;
  if (!strcmp(string, "month")) return adjuster::month;
  if (!strcmp(string, "day")) return adjuster::day;
  if (!strcmp(string, "hour")) return adjuster::hour;
  if (!strcmp(string, "minute")) return adjuster::minute;
  if (!strcmp(string, "second")) return adjuster::second;
  if (!strcmp(string, "last_day_of_month")) return adjuster::last_day_of_month;

  r_abort("'%s' is not a recognized `adjuster` option.", string);
}
