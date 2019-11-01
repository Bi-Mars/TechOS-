#include "pcb.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Enqueue

void enqueueBlock(struct pcb *newBlock)
{
    struct pcb *temp;
    
    if(frontBlock == NULL)
    {
        frontBlock = newBlock;
        newBlock->next_PCB = &frontBlock;
        rearBlock = newBlock;
        newBlock->previous_PCB = &rearBlock;
    }

    else
    {
        temp = rearBlock;
        newBlock->previous_PCB = &rearBlock;
        rearBlock = newBlock;
        temp->previous_PCB = newBlock;
        newBlock->next_PCB = temp;
    }
   // free(temp);
    
}
//Dequeue

void dequeueBlock(struct pcb *deleteMe)
{
    struct pcb *temp;
    if(frontBlock == NULL)
    {
        printf("There are no PCB in blocked queue");
    }

    else
    {
        temp = frontBlock;

        if(temp->next_PCB == &rearBlock)
        {
            frontBlock = NULL;
            rearBlock = NULL;
        }

        else
        {
            frontBlock = temp->previous_PCB;
            temp->previous_PCB->next_PCB = &frontBlock;
        }
        
    }
    
   // free(temp);
}


//remove PCB from block queue
int removeBlock(struct pcb *deleteMe)
{
    struct pcb *temp;

    temp = rearBlock;

    if(temp == deleteMe)
    {
        if(temp->next_PCB == (&frontBlock))
        {
            frontBlock = NULL;
            rearBlock = NULL;
        //    free(temp);
            return 0;
        }

        else
        {   
            rearBlock = temp->next_PCB;
            temp->previous_PCB = &rearBlock;
        }
      //  free(temp);
        return 1; // successfully removed
    }
    else
    {
         while(temp != deleteMe && temp->next_PCB != (&frontBlock))
        {
         temp = temp->next_PCB;
        }
        
        if(temp == deleteMe)
        {
            if(temp->next_PCB == &frontBlock)
            {
                temp->previous_PCB->next_PCB = &frontBlock;
                frontBlock = temp->previous_PCB;
              //  free(temp);
                return 1;
            }

            else
            {
                temp->next_PCB->previous_PCB = temp->previous_PCB;
                temp->previous_PCB->next_PCB = temp->next_PCB;
              //  free(temp);
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
struct pcb* checkBlockPCB(char *pname)
{
        struct pcb *temp;
        char *name;
        int compare;

    if(rearBlock == NULL)
    {
        return NULL;
    }

    else
    {
        temp = rearBlock;
        name = temp->pid;

        compare = strcmp(pname, temp->pid);
        while((compare != 0) && (temp->next_PCB) != (&frontBlock))
        {
            temp = temp->next_PCB;
        }

        if(compare == 0)
        {
          //  free(name);
            return temp;
        }

        else
        {
          //  free(name);
           // free(temp);
            return NULL;
        }
        
    }
}

void traverseBlock()
{
    struct pcb *temp = rearBlock;

    if(rearBlock == NULL)
    {
        printf("No PCB in blocked Queue.\n");
    }
    else
    {
    while(temp != &frontBlock)
    {
        printf("Process' ID: %s\n", temp->pid);
        printf("Process' Class: %d. 0 stands for system process and 1 stands for application process\n", temp->pclass);
        printf("Process' priority: %d\n", temp->priority);
        printf("process' state %d. 0 stands for ready state, 1 stands for running state and 2 stands for blocked state\n", temp->state_rrb);
        printf("Process' suspend status: %d. 0 stands for n0n-suspended and 1 stands for suspended.\n", temp->suspend);
        printf("Process' next Process ID: %s\n", temp->next_PCB->pid);
        printf("process' previous process ID: %s\n", temp->previous_PCB->pid);
        ("---------------------------------------------------------------------------------------------------------------------\n");
        temp = temp->next_PCB;
    }
    }
  //  free(temp);
}