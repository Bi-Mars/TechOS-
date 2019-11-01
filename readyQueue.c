#include "pcb.h"
#include "queue.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>


void enqueueReady(struct pcb *newPCB)
{
    struct pcb *temp;
    
     if(frontReady == NULL) // if the queue is empty
     {
         frontReady = newPCB;
         newPCB->previous_PCB = &frontReady; // store address of frontReady into newPCB->previous_PCB
          rearReady = newPCB;
         newPCB->next_PCB = &rearReady; // store address of frontReady into newPCB->previous_PCB
         printf(" PCB after added to queue %s\n", frontReady->pid);
        // temp = q->front;
     }

    else if(newPCB-> priority > frontReady->priority)
    {
        //printf("temp->priority %d.\n", temp->priority);
        newPCB->next_PCB = frontReady;
        frontReady->previous_PCB = newPCB;
        frontReady = newPCB;
        newPCB->previous_PCB = &frontReady;
        
    }
     else
     {
           temp = frontReady;
         while(!(newPCB->priority > temp->priority) && (temp->next_PCB != &rearReady))
            {
                printf("enqueueReady priority %d \n", temp->priority);
             temp = temp->next_PCB;
            }

        if(newPCB->priority > temp->priority)
        {
            newPCB->next_PCB = temp;
            newPCB->previous_PCB = temp->previous_PCB;
            temp->previous_PCB = newPCB;
            temp = newPCB->previous_PCB;
            temp->next_PCB = newPCB;
           
         }

        else
        {
                newPCB->previous_PCB = temp;
                temp->next_PCB = newPCB;
                rearReady = newPCB;
                newPCB->next_PCB = &rearReady;
        }
     }

   //  free(temp);
}


//dequeue
void dequeueReady()
{
    struct pcb *temp = frontReady;
    //dequeue from front
    frontReady = temp->next_PCB;
    temp->next_PCB->previous_PCB = &frontReady;
    printf("process successfully removed from Ready queue\n");  
   // free(temp);
}

int removeReady(struct pcb *deleteMe)
{
    struct pcb *temp;

    temp = frontReady;

    if(temp == deleteMe)
    {
        if(temp->previous_PCB == (&rearBlock))
        {
            frontBlock = NULL;
            rearBlock = NULL;
            //free(temp);
            return 0;
        }

        else
        {
            frontReady = temp->next_PCB; 
        temp->next_PCB->previous_PCB = &frontReady;
        // printf("process successfully removed from Ready queue\n");
        //free(temp);
     //   printf("about to return 1\n");
        return 1; // removed successfully
        //free(temp->pid);
        }
    }

    else
    {
        while(temp != deleteMe && temp->next_PCB != (&rearReady))
        {
            temp = temp->next_PCB;
        }
        if(temp == deleteMe)
        {
            if(temp->next_PCB == &rearBlock)
            {
                temp->next_PCB->previous_PCB = &rearBlock;
                rearBlock = temp->next_PCB;
               // free(temp);
                return 1;
            }

            else
            {
            temp->previous_PCB->next_PCB = temp->next_PCB;
            temp->next_PCB->previous_PCB = temp->previous_PCB;      
            //printf("process successfully removed from Ready queue\n");
          //  free(temp);
            return 1;  
            }
              
        }
        else
        {
           // free(temp);
            return 0;
             // printf("process not found\n");
        } 

    }     
}

//void traverse
struct pcb* checkReadyPCB(char *pname)
{
        char *name;
        struct pcb *temp; 
        int compare;

    if(frontReady == NULL)
    {
        //printf("No PCB inside Ready Queue.\n");
        return NULL;
    }


    else
    {
        temp = frontReady;
        name = temp->pid;  


        compare = strcmp(pname, temp->pid);
        

        while((compare != 0) && (temp->next_PCB != (&rearReady)))
        {
            temp = temp->next_PCB;
            compare = strcmp(pname, temp->pid);
        }

        if(compare == 0)
        {
           
            return temp;
        }
        else
        {
            return NULL;
        }
    }

}

void traverseReady()
{
    struct pcb *temp = frontReady;
    if(frontReady == NULL)
    {
        printf("No PCB in ready Queue.\n");
    }
    else
    {
    
    while(temp != &rearReady)
    {
        printf("Process' ID: %s\n", temp->pid);
        printf("Process' Class: %d. 0 stands for system process and 1 stands for application process\n", temp->pclass);
        printf("Process' priority: %d\n", temp->priority);
        printf("process' state %d. 0 stands for ready state, 1 stands for running state and 2 stands for blocked state\n", temp->state_rrb);
        printf("Process' suspend status: %d. 0 stands for n0n-suspended and 1 stands for suspended.\n", temp->suspend);
        printf("Process' next Process ID: %s\n", temp->next_PCB->pid);
        printf("process' previous process ID: %s\n", temp->previous_PCB->pid);
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        temp = temp->next_PCB;
    }
    }
    //free(temp);
}