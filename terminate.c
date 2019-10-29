#include <stdio.h>
#include <stdlib.h>
//#include "terminate.h"
#include "commands.h"

void terminate()
{
    printf("Are you sure you want to terminate?\n Enter 'Y' for Yes 'N' for No\n");

    char quit;
    scanf("%c", &quit);

    if(quit == 'Y' || quit == 'y')
    {
        exit(0);
    }

    else
    {
        printf("Please carry on your task.\n");
    }
    
}