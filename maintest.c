#include <stdio.h>
#include "commands.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>

int main()

{
    // initialize front and rear pointer to struct for ready queue
    frontReady = NULL;
    rearReady = NULL;


     char user_choice[20] ; //declare an array that holds characters. 20 memory slots
     char *pid = (char *) malloc(sizeof(char) * 32); //32 character long
     memset(pid, '\0', 32 * sizeof(char) );
    //take input from users
  
   do {
   
    
    /*fgets(char *str, int n, FILE *STREAM)
        * reads the user input from specified strem
        * Stores it into char pointer --> array of char
    */
        
     printf("\n PADJIP_BIMARSH TechOS>>> ");
        fgets(user_choice, 20, stdin);
    

     if(strcmp(user_choice, "createPCB\n") == 0)
        {
        // take user input and validate
             unsigned int pclass, priority;
        struct pcb *userReadyPCB, *userBlockPCB, *usersuspendReady, *usersuspendBlock;
        // pid = (char *) malloc();

        //------------------prompt for process name -------------------------------
       // while(strcmp(user_choice , "terminate\n") != 0)
       do {
            printf("Enter process name: \n");
            scanf("%s", pid); 
            printf("first pid %s\n", pid); 
           
            //check if the name already exist
            userReadyPCB = checkReadyPCB(pid);
            //printf("first pid %s\n", pid);
          //  printf(&userReadyPCB);

            if(userReadyPCB != NULL)
            {
                printf("Process Name already exist. The process %s currently resides in Ready Queue.\n", pid);
            }

        } while(strlen(pid) < 8 || userReadyPCB != NULL);

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
        printf("last pid %s\n", pid);
        }

        
    }  while(strcmp(user_choice , "terminate\n") != 0); // createPCB

    return 0;
}