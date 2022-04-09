#include "Calendar.h"

int leapyearfrom1600(int year) {
    return year/4-year/100+year/400-388; //Viktig med heltallsdivisjon
}

