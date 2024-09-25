#include "date.h"

int main_days_of_month() {
  uint8_t month = 0;
  while (month < 1 || month > 12) {
    printf("Mois [1, 12]: ");
    scanf("%hhu", &month);
  }
  int64_t year = 0;
  printf("Année: ");
  scanf("%ld", &year);
  printf("Nombre de jour dans le mois de %s (%hhu) %ld: %hhu\n", date_month_human_name_french(month), month, year, date_get_days_of_month(month, year));
  return EXIT_SUCCESS;
}

int main_duration_between_2_dates() {
  struct date *date1 = malloc(sizeof(struct date));
  date1->year = 2024;
  date1->month = 9;
  date1->day = 10;
  date1->hours = 18;
  date1->minutes = 34;
  date1->seconds = 25;
  date1->milliseconds = 76;
  date1->timezone_utc_offset = 0;

  string_t date1_iso_string = date_to_iso_string(date1);
  printf("%s\n", date1_iso_string);
  free(date1_iso_string);

  struct date *date2 = malloc(sizeof(struct date));
  date2->year = 2024;
  date2->month = 9;
  date2->day = 10;
  date2->hours = 18;
  date2->minutes = 34;
  date2->seconds = 0;
  date2->milliseconds = 0;
  date2->timezone_utc_offset = 0;

  string_t date2_iso_string = date_to_iso_string(date2);
  printf("%s\n", date2_iso_string);
  free(date2_iso_string);

  uint64_t duration_seconds = date_duration_seconds_between_2_dates(date1, date2);
  printf("Durée en secondes entre les deux dates: %lu\n", duration_seconds);

  free(date1);
  free(date2);

  return EXIT_SUCCESS;
}

int main_tomorrow_date() {
  struct date *date = date_from_iso_string("2024-09-10T20:34:25.076Z");
  string_t iso_string = date_to_iso_string_without_time(date);
  printf("Date: %s\n", iso_string);
  free(iso_string);

  date_add_hours(date, 24);
  iso_string = date_to_iso_string_without_time(date);
  printf("Date du lendemain: %s\n", iso_string);
  free(iso_string);

  date_add_hours(date, -48);
  iso_string = date_to_iso_string_without_time(date);
  printf("Date de hier: %s\n", iso_string);
  free(iso_string);

  free(date);
  return EXIT_SUCCESS;
}

string_t date_month_human_name_french(uint8_t month) {
  string_t months[] = {
      "Inconnu",
      "Janvier",
      "Février",
      "Mars",
      "Avril",
      "Mai",
      "Juin",
      "Juillet",
      "Août",
      "Septembre",
      "Octobre",
      "Novembre",
      "Décembre",
  };
  return date_get_is_valid_month(month) ? months[month] : months[0];
}
