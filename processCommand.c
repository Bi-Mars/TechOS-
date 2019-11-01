#include "commands.h"
#include <stdio.h>
#include <string.h>
#include "managePCB.h"
#include "queue.h"
#include <stdlib.h>

void createPCB(char *pid, unsigned int pclass, unsigned int priority)
{

 struct pcb *userReadyPCB = setupPCB(pid, pclass, priority);
    printf("The process has been successfully created.\n");


    enqueueReady(userReadyPCB);
    printf("    The process has been successfully added to ready queue.\n");
   // free(userReadyPCB);
}

void deletePCB(char *id)
{
    //check if the PCB exist
    struct pcb *temp = findPCB(id);
    remove_PCB(temp);
    
  //  freePCB(temp);
    //free(temp);
    
}


void blockPCB(char *id)
{
     struct pcb *tmpReady, *tmpBlock;
    tmpReady = checkReadyPCB(id);
   tmpBlock = checkBlockPCB(id);

    if(tmpReady != NULL)
    {
        int removed = removeReady(tmpReady);
        if(removed)
        {
            tmpReady->state_rrb = 2;
            enqueueBlock(tmpReady);
            printf("Process has been Blocked.\n");
        }

    }

    else
    {
        printf("Process Cannot be Blocked.\n");
    }
  // free(tmpBlock);
   // free(tmpReady);
    
}

void unblockPCB(char *id)
{
    
     struct pcb  *tmpBlock;
    tmpBlock = checkBlockPCB(id);

    if(tmpBlock != NULL)
    {
        removeBlock(tmpBlock);
        enqueueReady(tmpBlock);
        tmpBlock->state_rrb = 0;
        printf("Process has been unblocked.\n");
    }

    else
    {
        printf("Process not found");
    }
    //free(tmpBlock);

}

void suspendPCB(char *id)
{
    struct pcb *tmpReady, *tmpBlock;
    tmpReady = checkReadyPCB(id);
    tmpBlock = checkBlockPCB(id);

    if(tmpReady != NULL)
    {
        int check = removeReady(tmpReady);
        tmpReady->suspend = 1;
        enqueuesuspendReady(tmpReady);
        if(check)
        {
            printf("Process has been suspended and is currently in Suspend Ready Queue.\n");
        }
        
        //return tmpReady;
    }

    else if(tmpBlock != NULL)
    {
       int check = removeBlock(tmpBlock);
        tmpBlock->suspend = 1;
        enqueuesuspendBlock(tmpBlock);
        if(check)
        {
            printf("Process has been suspended and is currently in Suspend Block Queue.\n");
        }
        
    }

    else
    {
        printf("Process not found");
    }

  //  free(tmpReady);
    //free(tmpBlock);
}

void resumePCB(char *id)
{
     struct pcb  *tmpsuspendBlock, *tmpsuspendReady;
    tmpsuspendReady = checksuspendReady(id);
    tmpsuspendBlock = checksuspendBlock(id);

    if(tmpsuspendReady != NULL)
    {
       int removed = removesuspendReady(tmpsuspendReady);
       if(removed)
       {
           tmpsuspendReady->suspend=0;
        enqueueReady(tmpsuspendReady);
        printf("Process is resumed. Currently resides in ready Queue.\n");
       }
        
    }
    

    if(tmpsuspendBlock != NULL)
    {
        int removed = removesuspendBlock(tmpsuspendBlock);
        if(removed)
        {
            tmpsuspendBlock->suspend=0;
        enqueueBlock(tmpsuspendBlock);
        printf("Process is resumed. Currently resides in Blocked Queue.\n");
        }
        
    }

    else
    {
        printf("Process not found");
    }
    //free(tmpsuspendBlock);
    //free(tmpsuspendReady);
}

void setPriority(char *id, unsigned int priority)
{

    struct pcb *temp = findPCB(id);

    unsigned int state = temp->state_rrb;
    unsigned int suspended = temp->suspend;


    if(!temp)
    {
        printf("Process not found.\n");
    }

    else if(state == 0 && suspended == 0) // the process is in ready state
    {
        int removed = removeReady(temp);
        if(removed)
        {
             temp->priority = priority;
            enqueueReady(temp);
        }
         
    }

    else if (state == 0 && suspended == 1) // the process is in suspend ready queue
    {
        temp -> priority = priority;

    }

    else if (state == 2 && suspended == 0) // the process is in block queue
    {
        temp -> priority = priority;
    }

    else if (state == 2 && suspended == 1) // the process is in suspend block queue
    {
        temp -> priority = priority;
    }

    //free(pid);
   // free(temp);
}

void showPCB(char *id)
{

    struct pcb *temp = findPCB(id);
    printf("Process name: %s\n Class: %d\n State: %d\n Suspended Status: %d\n Priority: %d\n", temp->pid, temp->pclass, temp->state_rrb, temp->suspend, temp->priority);
 //   free(temp);
}



void showReadyProcess()
{
    traverseReady();
}


void showBlockedProcess()
{
    traverseBlock();
}

void showAllProcess()
{
    printf("-----------------Ready Queue-----------------\n");
    traverseReady();
    
    printf("-----------------Blocked Queue-----------------\n");
    traverseBlock();

    printf("-----------------Suspended Ready Queue-----------------\n");
    traversesuspendReady();

    printf("-----------------Suspended Block Queue-----------------\n");
    traversesuspendBlock();
}
