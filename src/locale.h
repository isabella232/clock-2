#ifndef CLOCK_LOCALE_H
#define CLOCK_LOCALE_H

#include "clock.h"
#include "enums.h"
#include <locale>

// -----------------------------------------------------------------------------

static
inline
std::pair<const std::string*, const std::string*>
fill_weekday_names(const cpp11::strings& day,
                   const cpp11::strings& day_ab,
                   std::string (&weekday_names)[14]) {
  for (int i = 0; i < 7; ++i) {
    std::string string = day[i];
    weekday_names[i] = string;
  }
  for (int i = 0; i < 7; ++i) {
    weekday_names[i + 7] = day_ab[i];
  }
  return std::make_pair(weekday_names, weekday_names+sizeof(weekday_names)/sizeof(weekday_names[0]));
}

static
inline
std::pair<const std::string*, const std::string*>
fill_month_names(const cpp11::strings& mon,
                 const cpp11::strings& mon_ab,
                 std::string (&month_names)[24]) {
  for (int i = 0; i < 12; ++i) {
    std::string string = mon[i];
    month_names[i] = string;
  }
  for (int i = 0; i < 12; ++i) {
    month_names[i + 12] = mon_ab[i];
  }
  return std::make_pair(month_names, month_names+sizeof(month_names)/sizeof(month_names[0]));
}

static
inline
std::pair<const std::string*, const std::string*>
fill_ampm_names(const cpp11::strings& am_pm, std::string (&ampm_names)[2]) {
  for (int i = 0; i < 2; ++i) {
    std::string string = am_pm[i];
    ampm_names[i] = string;
  }
  return std::make_pair(ampm_names, ampm_names+sizeof(ampm_names)/sizeof(ampm_names[0]));
}

// -----------------------------------------------------------------------------

class clock_numpunct : public std::numpunct<char>
{
private:
  const enum decimal_mark mark_;

public:
  explicit clock_numpunct(const decimal_mark& mark,
                          std::size_t refs = 0)
    : std::numpunct<char>(refs),
      mark_(mark)
    {}

  using typename std::numpunct<char>::char_type;

protected:
  virtual char_type do_decimal_point() const {
    return mark_ == decimal_mark::comma ? ',' : '.';
  }
};

// -----------------------------------------------------------------------------

#endif