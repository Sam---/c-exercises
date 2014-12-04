static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(
        int year,
        int month /* > 1 */ /* < 13 */,
        int day /* > 0 */ /* <= daytab[leap][month] */
) {
    int i;
    bool leap;
    if (month > 12 || month < 1) return -1;
    if (day < 1 || day > daytab[leap][month]) return -2;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(
        int year,
        int yearday /* i did it for one of them, that's good enought

