/*
- date.c initializes variables from date.h
*/

#include <windows.h>
//#include "date.h"
#include "commands.h"

day = 0 ;
month = 0;
year = 0;

void initialize(){
    SYSTEMTIME systemTime; // create variable of SYSTEM TIME
    GetSystemTime(&systemTime); // pass the address of stime 
    day = systemTime.wDay;
    month = systemTime.wMonth;
    year = systemTime.wYear;
}