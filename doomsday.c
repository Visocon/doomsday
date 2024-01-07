#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// variables
bool isLeapYear;

// functions

bool checkAnswer(char input[], char weekDay[]) {
    if (strcmp(weekDay, "0") == 0 && (strcmp(input, "0") == 0 || strcmp(input, "Sunday") == 0)) {return false;}
    else if (strcmp(weekDay, "1") == 0 && (strcmp(input, "1") == 0 || strcmp(input, "Monday") == 0)) {return false;}
    else if (strcmp(weekDay, "2") == 0 && (strcmp(input, "2") == 0 || strcmp(input, "Tuesday") == 0)) {return false;}
    else if (strcmp(weekDay, "3") == 0 && (strcmp(input, "3") == 0 || strcmp(input, "Wednesday") == 0 )) {return false;}
    else if (strcmp(weekDay, "4") == 0 && (strcmp(input, "4") == 0 || strcmp(input, "Thursday") == 0 )) {return false;}
    else if (strcmp(weekDay, "5") == 0 && (strcmp(input, "5") == 0 || strcmp(input, "Friday") == 0 )) {return false;}
    else if (strcmp(weekDay, "6") == 0 && (strcmp(input, "6") == 0 || strcmp(input, "Saturday") == 0 )) {return false;}
    else if (strcmp(input, "bypass") == 0) {exit(0);}
    else {return true;}
}

int findAnchorDay(int year) {
    double dFromAnchorYear = year - 1984;
    int daysAdded = dFromAnchorYear + floor(dFromAnchorYear/4);
    return (3 + daysAdded) % 7; // Because 1984 was a Wednesday (Trebles-day)
}

int findMonth(int day) {
    if (isLeapYear) {
        if (day <= 31) {return 1;}        // Jan
        else if (day <= 60) {return 2;}   // Feb
        else if (day <= 91) {return 3;}   // Mar
        else if (day <= 121) {return 4;}  // Apr
        else if (day <= 152) {return 5;}  // May
        else if (day <= 182) {return 6;}  // Jun
        else if (day <= 213) {return 7;}  // Jul
        else if (day <= 244) {return 8;}  // Aug
        else if (day <= 274) {return 9;}  // Sep
        else if (day <= 305) {return 10;} // Oct
        else if (day <= 335) {return 11;} // Nov
        else {return 12;}                 // Dec
    }
    else {
        if (day <= 31) {return 1;}        // Jan
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
}

int findMonthDay(int month, int day) {
    if (isLeapYear) {
        if (month == 1) {return day;}             // Jan
        else if (month == 2) {return day - 31;}   // Feb
        else if (month == 3) {return day - 60;}   // Mar
        else if (month == 4) {return day - 91;}   // Apr
        else if (month == 5) {return day - 121;}  // May
        else if (month == 6) {return day - 152;}  // Jun
        else if (month == 7) {return day - 182;}  // Jul
        else if (month == 8) {return day - 213;}  // Aug
        else if (month == 9) {return day - 244;}  // Sep
        else if (month == 10) {return day - 274;} // Oct
        else if (month == 11) {return day - 305;} // Nov
        else {return day - 335;}                  // Dec
    }
    else {
        if (month == 1) {return day;}             // Jan
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
}

int findWeekday(int anchorday, int day) {
    if (isLeapYear) {
        return ((anchorday + (day - 60)) % 7 + 7) % 7;
    }
    else {
        return ((anchorday + (day - 59)) % 7 + 7) % 7;
    }
}

int main() {
    int year, day, month, monthDay, dayOfTheWeek;
    char weekDayString[8];

    srand(time(NULL));
    year = (rand() % 40) + 1985;
    if (year % 4 == 0) {
        isLeapYear = true;
        day = (rand() % 366) + 1;
    }
    else {
        day = (rand() % 365) + 1; 
    }
    
    month = findMonth(day);
    monthDay = findMonthDay(month, day);
    dayOfTheWeek = findWeekday(findAnchorDay(year), day);

    bool wrongAnswer = true;
    char input[32];
    sprintf(weekDayString, "%d", dayOfTheWeek);
    printf("\n************\n");
    while (wrongAnswer) {
        printf("What day of the week is %d/%d/%d? ", month, monthDay, year);
        scanf("%s", input);
        wrongAnswer = checkAnswer(input, weekDayString);
    }
    printf("Correct!\n************\n");
}
