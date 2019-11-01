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
           "exit                         Exits the program. \n"
           "createPCB                    Creates Process Control Block.\n"
           "deletePCB                     Deletes Process Control Block.\n"
           "blockPCB                    Blocks Process Control Block.\n"
           "unblockPCB                    Unblocks Process Control Block.\n"
           "suspendPCB                    Suspends Process Control Block.\n"
           "resumePCB                    Resumes Process Control Block.\n"
           "setPriority                  set priority of Process Control Block.\n"
           "showPCB                    Displays Process Control Block.\n"
           "readyProcess                Displays Process Control Block from ready queue.\n"
           "blockProcess                 Displays Process Control Block from Block Queue\n"
           "allProcess                   Displays Process Control Block of all Queues.\n");
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