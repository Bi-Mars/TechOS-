/*
- This file initialize function declared in header file
*/

#include <stdio.h>
//#include "help.h"
#include "commands.h"

void help()
{
    printf("***** This is the help section *****\n"
           "***** Provides you with a Description of each Command*****\n"
           "List of Commands supported:\n");

    printf("version                      Displays current version of TechOS Project.\n"
           "date                         Displays current date in MM/DD/YY format.\n"
           "setdate                      Prompts for user input, in MM/DD/YY format and set the date.\n"
           "time                         Displays current time.\n"
           "terminate                    Terminates the program. \n");
}

void helpVersion()
{
    printf("This command prints the version of current Operating System.\n");
}

void helpdate()
{
    printf("This command displays current date of the system.\n");
}

void helpSetdate()
{
    printf("This command prompts the user for input, checks the validity and set the date of OS.\n");
}

void helptime()
{
    printf("This command displays current time of the system\n");
}

void helpterminate()
{
    printf("This command terminates the program.\n");
}