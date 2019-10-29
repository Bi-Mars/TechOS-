#include <stdio.h>
#include "commands.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
//#include "readyQueue.c"

int main()
{
    initializeReady();
    initializeBlock();
    initializesuspendReady();
    initializesuspendBlock();

    char user_choice[20] ; //declare an array that holds characters. 20 memory slots
     char *pid = (char *) malloc(sizeof(char) * 32); //32 character long

//take input from users
do{
    printf("\n PADJIP_BIMARSH TechOS>>> ");
    
    /*fgets(char *str, int n, FILE *STREAM)
        * reads the user input from specified strem
        * Stores it into char pointer --> array of char
    */
    fgets(user_choice, 20, stdin);
    

    // strlwr(string) --> coverts given string into lower case
    if(strcmp(user_choice, "createPCB\n") == 0)
    {
        // take user input and validate
       
        unsigned int pclass, priority;
        struct pcb *userReadyPCB, *userBlockPCB, *usersuspendReady, *usersuspendBlock;
        // pid = (char *) malloc();

        //------------------prompt for process name -------------------------------
        do
        {
            printf("Enter process name: \n");
            scanf("%s", pid);  
           
            //check if the name already exist
            userReadyPCB = checkReadyPCB(pid);
          
            userBlockPCB = checkBlockPCB(pid);
           
            usersuspendReady = checksuspendReady(pid);
        
            usersuspendBlock = checksuspendBlock(pid);
            
            
            if(usersuspendReady != NULL)
            {
                printf("Process Name already exist. The process %s currently resides in suspend Ready Queue.\n", pid);
            }

           else if(usersuspendBlock != NULL)
            {
                printf("Process Name already exist. The process %s currently resides in suspend Block Queue.\n", pid);
            }

            else if(userReadyPCB != NULL)
            {
                printf("Process Name already exist. The process %s currently resides in Ready Queue.\n", pid);
            }

            else if (userBlockPCB != NULL)
            {
                printf("process name already exist. The process %s currently resides in Block queue.\n", pid);
            }
        
        } while(strlen(pid) < 8 && userReadyPCB!= NULL && userBlockPCB != NULL && usersuspendBlock != NULL && usersuspendReady!= NULL);

        //----------------------------- Prompt for process class --------------------------------
        do
        {
            printf("Enter the process class: 0 for system process and 1 for application process.\n");
            scanf("%d", &pclass);
        } while (pclass<0 || pclass>1);

        // ------------------------------ prompt for priority ----------------------------------
        do
        {
            printf("Assign the priority to the process: 0-9.\n");
            scanf("%d", &priority);
        } while (priority<0 || priority>9);

        
        createPCB(pid, pclass, priority); // call this function from managePCB.c
    } // createPCB

//-------------------------deletePCB -------------------------------------------------------------------------
    else if(strcmp(user_choice, "deletePCB\n") == 0)
    {

        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid 
        deletePCB(pid); // call this fuction from managePCB.c

    }

//---------------------------BLOCK PCB ---------------------------------
    else if(strcmp(user_choice, "blockPCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid 
        blockPCB(pid); // call this function from managePCB.c

    }

    else if(strcmp(user_choice, "unblockPCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid
        unblockPCB(pid); // call this function from managePCB.c

    }

    else if(strcmp(user_choice, "suspendPCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid
        suspendPCB(pid); // call this function from help.c

    }// help set date

    else if(strcmp(user_choice, "resumePCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid
        resumePCB(pid); // call this function from help.c

    }// help time

     else if(strcmp(user_choice, "setPriority\n") == 0)
    {
        printf("Enter process name that you would like to Block.\n");
        scanf("%s", pid);

        unsigned int priority;
        printf("Enter process prority. Enter between 0 to 9\n");
        scanf("%d", &priority);

        setPriority(pid, priority); // call this function from help.c

    }// help terminate

    else if (strcmp(user_choice, "showPCB\n") == 0)
    {
        printf("Enter process name that you would like to Block.\n");
        scanf("%s", pid);
        showPCB(pid); // call this function from terminate.c
    }

    else if(strcmp(user_choice, "readyProcess\n") == 0)
    {
        showReadyProcess(); // call this function from viewdate.c
    }


    else if(strcmp(user_choice, "blockProcess\n") == 0)
    {
        showBlockedProcess();
    }

    else if(strcmp(user_choice, "allProcess\n") == 0)
    {
        showAllProcess(); // call this function from time.c
    }
   

    else
    {
        printf("Enter Valid Command. Type help to look for commands.");
    }


} while(strcmp(user_choice , "terminate\n") != 0);


return 0;
}