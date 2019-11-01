#include "pcb.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Enqueue

void enqueuesuspendReady(struct pcb *newBlock)
{
    struct pcb *temp;
    
    if(frontsusReady == NULL)
    {
        frontsusReady= newBlock;
        newBlock->next_PCB = &frontsusReady;
        rearsusReady = newBlock;
        newBlock->previous_PCB = &rearsusReady;
    }

    else
    {
        temp = rearsusReady;
        newBlock->previous_PCB = &rearsusReady;
        rearsusReady = newBlock;
        temp->previous_PCB = newBlock;
        newBlock->next_PCB = temp;
    }
   // free(temp);
    
}
//Dequeue

void dequeuesuspendReady(struct pcb *deleteMe)
{
    struct pcb *temp;
    if(frontsusReady == NULL)
    {
        printf("There are no PCB in suspend ready queue");
    }

    else
    {
        temp = frontsusReady;

        if(temp->next_PCB == &rearsusReady)
        {
            frontsusReady = NULL;
            rearsusReady = NULL;
        }

        else
        {
            frontsusReady = temp->previous_PCB;
            temp->previous_PCB->next_PCB = &frontsusReady;
        }
        
    }
    
   // free(temp);
}


//remove PCB from block queue
int removesuspendReady(struct pcb *deleteMe)
{
    struct pcb *temp;

    temp = rearsusReady;

    if(temp == deleteMe)
    {
        if(temp->next_PCB == (&frontsusReady))
        {
            frontsusReady = NULL;
            rearsusReady = NULL;
            //free(temp);
            return 0;
        }

        else
        {   
            rearsusReady = temp->next_PCB;
            temp->previous_PCB = &rearsusReady;
        }
       // free(temp);
        return 1; // successfully removed
    }
    else
    {
         while(temp != deleteMe && temp->next_PCB != (&frontsusReady))
        {
         temp = temp->next_PCB;
        }
        
        if(temp == deleteMe)
        {
            if(temp->next_PCB == &frontsusReady)
            {
                temp->previous_PCB->next_PCB = &frontsusReady;
                frontsusReady = temp->previous_PCB;
               // free(temp);
                return 1;
            }

            else
            {
                temp->next_PCB->previous_PCB = temp->previous_PCB;
                temp->previous_PCB->next_PCB = temp->next_PCB;
             //   free(temp);
                return 1;
            }
        }
        else
        {

            printf("Process not found\n");
           //  free(temp);
            return 0;
        }  
       
    }     
}

//void traverse
struct pcb* checksuspendReady(char *pname)
{
        struct pcb *temp;
        char *name;
        int compare;

    if(rearsusReady == NULL)
    {
        return NULL;
    }

    else
    {
        temp = rearsusReady;
        name = temp->pid;

        compare = strcmp(pname, temp->pid);
        while((compare != 0) && (temp->next_PCB) != (&frontsusReady))
        {
            temp = temp->next_PCB;
        }

        if(compare == 0)
        {
            return temp;
        }

        else
        {
          //  free(temp);
            return NULL;
        }
        
    }
}

void traversesuspendReady()
{
    struct pcb *temp = rearsusReady;
if(rearsusReady == NULL)
    {
        printf("No PCB in suspend ready Queue.\n");
    }
    else
    {

    while(temp != &frontsusReady)
    {
        printf("Process' ID: %s\n", temp->pid);
        printf("Process' Class: %d. 0 stands for system process and 1 stands for application process\n", temp->pclass);
        printf("Process' priority: %d\n", temp->priority);
        printf("process' state %d. 0 stands for ready state, 1 stands for running state and 2 stands for blocked state\n", temp->state_rrb);
        printf("Process' suspend status: %d. 0 stands for n0n-suspended and 1 stands for suspended.\n", temp->suspend);
        printf("Process' next Process ID: %s\n", temp->next_PCB->pid);
        printf("process' previous process ID: %s\n", temp->previous_PCB->pid);
        ("---------------------------------------------------------------------------------------------------------------------");
        temp = temp->next_PCB;
    }
    }
  //  free(temp);
}