#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <sys/time.h>

#include "commands.h"
#include "queue.h"
#include "greetings.h"


  void main()
{
  // greetings
  greet();
  initialize(); //date.c

  // create an array of char, input will be stored in this array
  char str[20];
  char *pid = (char *) malloc(sizeof(char) * 32); //32 character long
  memset(pid, '\0', 32 * sizeof(char) );

  do
  {
    /* get the user's input. Store the input in str array
     * fgets(char *str, int n, FILE *stream)
     * reads a line from the specified stream and
     * stores it into the string pointed by str
     */

    printf("\n PADJIP_BIMARSH TechOS>>> ");
    fgets(str, 20, stdin);

    // if the input is "help" --> strcmp (comapares the string)
    if(strcmp(str, "help\n") == 0)
    {
      //call help method from library
      help();
    }

    else
      if (strcmp(str, "version\n") == 0)
    {
      //call version from the library
      version();
    }


    else
      if (strcmp(str, "date\n") == 0)
    {
      //call date from the library
      viewdate();
    }

    else if (strcmp(str, "time\n") == 0)
    {
      //call time from the library
      viewtime();
    }


    else if (strcmp(str, "setdate\n") == 0)
    {
      askDate();
    }

    else if (strcmp(str, "exit\n") == 0)
    {
        terminate();
    }

     else if(strcmp(str, "createPCB\n") == 0)
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
        
        } while(strlen(pid) < 8 || userReadyPCB!= NULL || userBlockPCB != NULL || usersuspendBlock != NULL || usersuspendReady != NULL);

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
    else if(strcmp(str, "deletePCB\n") == 0)
    {

        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid 
        deletePCB(pid); // call this fuction from managePCB.c

    }

//---------------------------BLOCK PCB ---------------------------------
    else if(strcmp(str, "blockPCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid 
        blockPCB(pid); // call this function from managePCB.c

    }

    else if(strcmp(str, "unblockPCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid
        unblockPCB(pid); // call this function from managePCB.c

    }

    else if(strcmp(str, "suspendPCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid
        suspendPCB(pid); // call this function from help.c

    }// help set date

    else if(strcmp(str, "resumePCB\n") == 0)
    {
        printf("Enter process name: \n");
        scanf("%s", pid); //%ms tells compiler to take all string and store the pointer to first character to pid
        resumePCB(pid); // call this function from help.c

    }// help time

     else if(strcmp(str, "setPriority\n") == 0)
    {
        printf("Enter process name that you would like to change the priority.\n");
        scanf("%s", pid);

        unsigned int priority;
        printf("Enter process prority. Enter between 0 to 9\n");
        scanf("%d", &priority);

        setPriority(pid, priority); // call this function from help.c

    }// help terminate

    else if (strcmp(str, "showPCB\n") == 0)
    {
        printf("Enter process name that you would like to view.\n");
        scanf("%s", pid);
        showPCB(pid); // call this function from terminate.c
    }

    else if(strcmp(str, "readyProcess\n") == 0)
    {
        showReadyProcess(); // call this function from viewdate.c
    }


    else if(strcmp(str, "blockProcess\n") == 0)
    {
        showBlockedProcess();
    }

    else if(strcmp(str, "allProcess\n") == 0)
    {
        showAllProcess(); // call this function from time.c
    }
   

  }while (str != "exit");
}
