#ifndef __TP1_DATE__
#define __TP1_DATE__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../dependencies/libcproject/libcproject.h"

int main_days_of_month();

int main_duration_between_2_dates();

int main_tomorrow_date();

/**
 * @brief Get the human name of a month in French.
 *
 * @param month
 * @return string_t
 *
 * @code
 * date_month_human_name_french(1) // "Janvier"
 * @endcode
 */
string_t date_month_human_name_french(uint8_t month);

#endif
