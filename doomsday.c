#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// variables
bool isLeapYear;

// functions
int findMonth(int day) {
    if (day < 1 || day > 365) {
        printf("ERROR: findMonth input invalid: %d\n", day); 
        exit(1);
    }
    else if (day <= 31) {return 1;}   // Jan
    else if (day <= 59) {return 2;}   // Feb
    else if (day <= 90) {return 3;}   // Mar
    else if (day <= 120) {return 4;}  // Apr
    else if (day <= 151) {return 5;}  // May
    else if (day <= 181) {return 6;}  // Jun
    else if (day <= 212) {return 7;}  // Jul
    else if (day <= 243) {return 8;}  // Aug
    else if (day <= 273) {return 9;}  // Sep
    else if (day <= 304) {return 10;} // Oct
    else if (day <= 334) {return 11;} // Nov
    else {return 12;}                 // Dec
}

int findMonthDay(int month, int day) {
    if (month < 1 || month > 12) {
        printf("ERROR: findMonthDay 'month' input invalid: %d\n", month);
        exit(1);
    }
    if (day < 1 || day > 365) {
        printf("ERROR: findMonthDay 'day' input invalid: %d\n", month);
        exit(1);
    }
    if (month == 1) {return day;}         // Jan
    else if (month == 2) {return day - 31;}   // Feb
    else if (month == 3) {return day - 59;}   // Mar
    else if (month == 4) {return day - 90;}   // Apr
    else if (month == 5) {return day - 120;}  // May
    else if (month == 6) {return day - 151;}  // Jun
    else if (month == 7) {return day - 181;}  // Jul
    else if (month == 8) {return day - 212;}  // Aug
    else if (month == 9) {return day - 243;}  // Sep
    else if (month == 10) {return day - 273;} // Oct
    else if (month == 11) {return day - 304;} // Nov
    else {return day - 334;}                  // Dec
}

int findWeekday(int anchorday, int day) {
    if (isLeapYear) {
        return 0;
    }
    else {
        return ((anchorday + abs(day - 59)) % 7);
    }
}

int main() {
    int day, month, monthDay, dayOfTheWeek;

    srand(time(NULL));
    day = (rand() % 365) + 1; // program assumes 2023, a non-leap-year

    month = findMonth(day);

    monthDay = findMonthDay(month, day);

    dayOfTheWeek = findWeekday(2, day); // assuming 2023, a year with doomsdays on tuesday (twos-day)
    
    printf("%d = %d/%d, %d\n", day, month, monthDay, dayOfTheWeek);
}
