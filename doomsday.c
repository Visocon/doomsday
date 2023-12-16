#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// variables

// functions
int findMonth(int day) {
    if (day < 0 || day > 364) {
        printf("ERROR: findMonth input invalid: %d\n", day); 
        exit(1);
    }
    else if (day <= 30) {return 1;}   // Jan
    else if (day <= 58) {return 2;}   // Feb
    else if (day <= 89) {return 3;}   // Mar
    else if (day <= 119) {return 4;}  // Apr
    else if (day <= 150) {return 5;}  // May
    else if (day <= 180) {return 6;}  // Jun
    else if (day <= 211) {return 7;}  // Jul
    else if (day <= 242) {return 8;}  // Aug
    else if (day <= 272) {return 9;}  // Sep
    else if (day <= 303) {return 10;} // Oct
    else if (day <= 333) {return 11;} // Nov
    else {return 12;}                 // Dec
}

int findMonthDay(int month, int day) {
    if (month < 1 || month > 12) {
        printf("ERROR: findMonthDay 'month' input invalid: %d\n", month);
        exit(1);
    }
    if (day < 0 || day > 364) {
        printf("ERROR: findMonthDay 'day' input invalid: %d\n", month);
        exit(1);
    }
    if (month == 1) {return day + 1;}         // Jan
    else if (month == 2) {return day - 30;}   // Feb
    else if (month == 3) {return day - 58;}   // Mar
    else if (month == 4) {return day - 89;}   // Apr
    else if (month == 5) {return day - 119;}  // May
    else if (month == 6) {return day - 150;}  // Jun
    else if (month == 7) {return day - 180;}  // Jul
    else if (month == 8) {return day - 211;}  // Aug
    else if (month == 9) {return day - 242;}  // Sep
    else if (month == 10) {return day - 272;} // Oct
    else if (month == 11) {return day - 303;} // Nov
    else {return day - 333;}                  // Dec
}
/*
int findWeekday(int anchorday, int day) {
    
}
*/
int main() {
    int day;

    srand(time(NULL));
    day = rand() % 365; // program assumes 2023, a non-leap-year

    //int dayOfTheWeek = findWeekday(2, day); // assuming 2023, a year with doomsdays on tuesday (twos-day)

    printf("%d/%d", findMonth(116), findMonthDay(findMonth(116), 116));
}

