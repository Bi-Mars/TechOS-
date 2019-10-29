//#include "time.h"
#include<stdio.h>
#include <time.h>
#include "commands.h"

void viewtime()
{
  int hours, minutes, seconds;

    // arithmetic time type
    time_t rawtime;

    // obtain current time
    //time() returns the current time of the system as time_t value
     time(&rawtime);

     // localtime() converts a time_t value to calender time and returns
     //pointer to a tm sturcture with its member filled with corresponding values
      struct tm *info = localtime(&rawtime);

    hours = info -> tm_hour;
    minutes = info -> tm_min;
    seconds = info -> tm_sec;

    //print local time
    if (hours < 12)
    {
        printf("Time is: %02d:%02d:%02d am\n", hours, minutes, seconds);
    }

    else
    {
        printf("Time is: %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    }   
}