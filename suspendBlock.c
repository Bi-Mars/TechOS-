#include "pcb.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Enqueue

void enqueuesuspendBlock(struct pcb *newBlock)
{
    struct pcb *temp;
    
    if(frontsusBlock == NULL)
    {
        frontsusBlock = newBlock;
        newBlock->next_PCB = &frontsusBlock;
        rearsusBlock = newBlock;
        newBlock->previous_PCB = &rearsusBlock;
    }

    else
    {
        temp = rearsusBlock;
        newBlock->previous_PCB = &rearsusBlock;
        rearsusBlock = newBlock;
        temp->previous_PCB = newBlock;
        newBlock->next_PCB = temp;
    }
   // free(temp);
    
}
//Dequeue

void dequeuesuspendBlock(struct pcb *deleteMe)
{
    struct pcb *temp;
    if(frontsusBlock == NULL)
    {
        printf("There are no PCB in suspend blocked queue");
    }

    else
    {
        temp = frontsusBlock;

        if(temp->next_PCB == &rearsusBlock)
        {
            frontsusBlock = NULL;
            rearsusBlock = NULL;
        }

        else
        {
            frontsusBlock = temp->previous_PCB;
            temp->previous_PCB->next_PCB = &frontsusBlock;
        }
        
    }
    
  //  free(temp);
}


//remove PCB from block queue
int removesuspendBlock(struct pcb *deleteMe)
{
    struct pcb *temp;

    temp = rearsusBlock;

    if(temp == deleteMe)
    {
        if(temp->next_PCB == (&frontsusBlock))
        {
            frontsusBlock = NULL;
            rearsusBlock = NULL;
          //  free(temp);
            return 0;
        }

        else
        {   
            rearsusBlock = temp->next_PCB;
            temp->previous_PCB = &rearsusBlock;
        }
      //  free(temp);
        return 1; // successfully removed
    }
    else
    {
         while(temp != deleteMe && temp->next_PCB != (&frontsusBlock))
        {
         temp = temp->next_PCB;
        }
        
        if(temp == deleteMe)
        {
            if(temp->next_PCB == &frontsusBlock)
            {
                temp->previous_PCB->next_PCB = &frontsusBlock;
                frontsusBlock = temp->previous_PCB;
             //   free(temp);
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
struct pcb* checksuspendBlock(char *pname)
{
        struct pcb *temp;
        char *name;
        int compare;

    if(rearsusBlock == NULL)
    {
        return NULL;
    }

    else
    {
        temp = rearsusBlock;
        name = temp->pid;

        compare = strcmp(pname, temp->pid);
        while((compare != 0) && (temp->next_PCB) != (&frontsusBlock))
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

void traversesuspendBlock()
{
    struct pcb *temp = rearsusBlock;

    if(rearsusBlock == NULL)
    {
        printf("No PCB in suspended block queue\n");

    }

    else
    {

    while(temp != &frontsusBlock)
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