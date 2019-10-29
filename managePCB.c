#include "pcb.h"
#include "managePCB.h"
#include "queue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
This procedure allocates memory for a new PCB
    Dynamic allocation of memory:
        because we don't know the exact size of PCB
It returns pointer to the new PCB
*/

   
struct pcb *allocatePCB()
{   
    struct pcb *newPCB; // newPCB holds address/location of newly created PCB
   /*
        // the following line of code tells the compiler that
         we want to dynamically allocate just enough space to hold PCB
         and then return a pointer to the newly allocated data
   */
   
    newPCB = (struct pcb *) malloc(sizeof(struct pcb)); 
    newPCB->pid = (char *) malloc(sizeof(char) * 32); // allocate dynamic size for name of the process

    return newPCB;
}

/*
    This procedure calls allocatePCB to create empty PCB and initialize all the required information
*/
struct pcb *setupPCB(char *pid, unsigned int pClass, unsigned int pPriority)
{
    struct pcb *justCreatedPCB = allocatePCB();

    //initialize component of PCB
   // justCreatedPCB->pid = pid + '\0';
   //strcpy(destination, source,n) --> function that copy source string into destination string
    // length of destination must be greater or equals to source, not less
    strcpy(justCreatedPCB->pid, pid);
    justCreatedPCB->pclass = pClass; //process class
    justCreatedPCB->priority = pPriority; // process priority
    justCreatedPCB->state_rrb = 0; // 0 indicates PCB is in ready state
    justCreatedPCB->suspend = 0; //not suspended
    justCreatedPCB->next_PCB = NULL;
    justCreatedPCB->previous_PCB = NULL;

    // add the pcb to ready queue
    return justCreatedPCB;
    
}

/*
    This procedure free all memory associated with a given PCB
*/
void freePCB(struct pcb *freeMe)
{   
    if(removeReady(freeMe)) // if ther exist PCB in readyQueue
    {
        free(freeMe->pid);
        free(freeMe);
        printf("Successfully removed PCB from ready Queue");
    }
    else if(removeBlock(freeMe))
    {
        free(freeMe->pid);
         free(freeMe);
         printf("Successfully removed PCB from Blocked Queue");
    }

    else if(removesuspendBlock(freeMe))
    {
        free(freeMe->pid);
         free(freeMe);
         printf("Successfully removed PCB from Suspend Blocked Queue");
    }

    else if(removesuspendReady(freeMe))
    {
       
         free(freeMe->pid);
         free(freeMe);
         printf("Successfully removed PCB from Blocked Queue");
    }
    else
    {
        printf("Process not found.\n");
    }
       
}

struct pcb* findPCB(char *pname)
{
    struct pcb* tmpReady, *tmpBlock, *tmpsuspendReady, *tmpsuspendBlock;
    tmpReady = checkReadyPCB(pname);
    tmpBlock = checkBlockPCB(pname);
    tmpsuspendBlock = checksuspendBlock(pname);
    tmpsuspendReady = checksuspendReady(pname);
    

    if(!tmpReady)
    {
        return tmpReady;
    }

    else if(!tmpBlock)
    {
        return tmpBlock;
    }

    if(!tmpsuspendReady)
    {
        return tmpsuspendReady;
    }

    if(!tmpsuspendBlock)
    {
        return tmpsuspendBlock;
    }

    else
    {
        printf("Process not found");
        return NULL;
    }

    free(tmpReady);
    free(tmpBlock);
    free(tmpsuspendReady);
    free(tmpsuspendBlock);
    
}



/*
  This procedure will insert PCB into appropriate queue
*/
void insertPCB(struct pcb *insertMe)
{
    //to insert PCB into appropriate queue, we need the current state of the queue
   

    //if current_state is 0
}

void remove_PCB(struct pcb *removeMe)
{
    if(removeReady(removeMe))
    {
        dequeueReady(removeMe);
        printf("Successfully removed the process from Ready Queue.\n");
    }
    else if(removeBlock(removeMe))
    {
        dequeueBlock(removeMe);
        printf("Successfully removed the process from Blocked Queue.\n");

    }

    else if(removesuspendBlock(removeMe))
    {
        dequeuesuspendBlock(removeMe);
        printf("Successfully removed the process from Blocked Queue.\n");

    }

    else if(removesuspendReady(removeMe))
    {
        dequeuesuspendReady(removeMe);
        printf("Successfully removed the process from Blocked Queue.\n");

    }
}