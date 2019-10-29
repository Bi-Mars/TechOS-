
//Import Libraries
#include <stdio.h>
#include <string.h>
#include <windows.h>

//import .h files
/*
#include "date.h"
#include "help.h"
#include "viewdate.h"
#include "version.h"
#include "setdate.h"
#include "terminate.h"
*/
#include "commands.h"

//main
int main(void){

 initialize(); // call this function from date.c

// Declare Global Variable
char user_choice[20] ; //declare an array that holds characters. 20 memory slots

//take input from users
do{
    printf("\n PADJIP_BIMARSH TechOS>>> ");
    
    /*fgets(char *str, int n, FILE *STREAM)
        * reads the user input from specified strem
        * Stores it into char pointer --> array of char
    */
    fgets(user_choice, 25, stdin);
    

    // strlwr(string) --> coverts given string into lower case
    if(strcmp(strlwr(user_choice), "version\n") == 0)
    {
        version(); // call this function from version.c
    } // version

    else if(strcmp(strlwr(user_choice), "help\n") == 0)
    {
        help(); // call this fuction from help.c

    }// help

    else if(strcmp(strlwr(user_choice), "help version\n") == 0)
    {
        helpVersion(); // call this function from help.c

    }// help version

    else if(strcmp(strlwr(user_choice), "help date\n") == 0)
    {
        helpdate(); // call this function from help.c

    }// help date

    else if(strcmp(strlwr(user_choice), "help setdate\n") == 0)
    {
        helpSetdate(); // call this function from help.c

    }// help set date

    else if(strcmp(strlwr(user_choice), "help time\n") == 0)
    {
        helptime(); // call this function from help.c

    }// help time

     else if(strcmp(strlwr(user_choice), "help terminate\n") == 0)
    {
        helpterminate(); // call this function from help.c

    }// help terminate

    else if (strcmp(strlwr(user_choice), "terminate\n") == 0)
    {
        terminate(); // call this function from terminate.c
    }

    else if(strcmp(strlwr(user_choice), "date\n") == 0)
    {
        viewdate(); // call this function from viewdate.c
    }


    else if(strcmp(strlwr(user_choice), "setdate\n") == 0)
    {
        askDate();
        setdate(); // call this function from setdate.c
    }

    else if(strcmp(strlwr(user_choice), "time\n") == 0)
    {
        viewtime(); // call this function from time.c
    }
   

    else
    {
        printf("Enter Valid Command. Type help to look for commands.");
    }


} while(strcmp(user_choice , "terminate\n") != 0);



return 0;

}
