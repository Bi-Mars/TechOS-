#include "pcb.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct queue *q;

void initializesuspendBlock( )
{
    q = (struct queue*) malloc(sizeof(struct queue));
    q->count = 0;
    q->front = NULL;
    q-> rear =  NULL;
}

int isEmptysuspendBlock()
{
    if(q->front== NULL)
    {
        return (q->front == NULL);
    }
    return 1;
}

//Enqueue

void enqueuesuspendBlock(struct pcb *newBlock)
{
    struct pcb *temp;
    temp = q->front;

    if(isEmptysuspendBlock())
    {
        q->front = newBlock;
        newBlock->previous_PCB = q->front;
        q->rear = newBlock;
        newBlock->next_PCB = q->rear;
    }

    else
    {
       newBlock->next_PCB =  q->front;
       q->front = newBlock;
       newBlock->previous_PCB = q->front;
       temp->previous_PCB = newBlock;
    }
    q->count++;
    free(temp);
    
}
//Dequeue

void dequeuesuspendBlock(struct pcb *deleteMe)
{
    struct pcb *temp = q->rear;
    q->rear = temp->previous_PCB;
    temp->previous_PCB->next_PCB = q->rear;
    q->count--;
    free(temp);
}


//remove PCB from block queue
int removesuspendBlock(struct pcb *deleteMe)
{
    struct pcb *temp;

    temp = q->front;

    if(temp == deleteMe)
    {
        q->front = temp->next_PCB; 
        temp->next_PCB->previous_PCB = q->front;
          printf("process successfully removed from suspend ready queue\n");
        free(temp);
        q->count--;
        return 1;
       
    }

    else
    {
         while(temp != deleteMe && temp->next_PCB != q->rear)
        {
         temp = temp->next_PCB;
        }
        if(temp == deleteMe)
        {
            temp->previous_PCB->next_PCB = temp->next_PCB;
            temp->next_PCB->previous_PCB = temp->previous_PCB;
            printf("process successfully removed from suspend ready queue\n");
            q->count--;
            free(temp);
            return 1;
        }
        else
        {
            printf("Process not found\n");
            
        }     
       
    }

free(temp);
return 0;   
     
}

//void traverse
struct pcb* checksuspendBlock(char *pname)
{
        struct pcb *temp;
        temp = q->front;

        if(temp !=NULL)
        {
    int compare = strcmp(pname, temp->pid); // returns 0 is they are equal

        while( compare != 0 && temp->next_PCB != q->rear)
        {
            temp =  temp -> next_PCB;
            compare = strcmp(pname, temp->pid);
        }

            compare = strcmp(pname, temp->pid);


         if( compare == 0 )
        {
            return temp; // PCB of given pid exist
        }
        }

        return NULL;

}

void traversesuspendBlock()
{
    struct pcb *temp = q->front;

    while(temp->next_PCB != q->rear)
    {
        printf("Process' ID: %s\n", temp->pid);
        printf("Process' Class: %d. 0 stands for system process and 1 stands for application process\n", temp->pclass);
        printf("Process' priority: %d\n", temp->priority);
        printf("process' state %d. 0 stands for ready state, 1 stands for running state and 2 stands for blocked state\n", temp->state_rrb);
        printf("Process' suspend status: %d. 0 stands for n0n-suspended and 1 stands for suspended.\n", temp->suspend);
        printf("Process' next Process ID: %s\n", temp->next_PCB->pid);
        printf("process' previous process ID: %s\n", temp->previous_PCB->pid);
        temp = temp->next_PCB;
    }
}