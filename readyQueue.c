#include "pcb.h"
#include "queue.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>



struct queue *readyq ;
void initializeReady()
{
    //create an instance of queue:
  readyq = (struct queue*) malloc(sizeof(struct queue));

  //initialize the queue
  readyq->count = 0;
  readyq->front= NULL;
  readyq->rear = NULL;
}

int isEmptyReady()
{
    if(readyq->front != NULL)
    {
        return (readyq->front == NULL);
    }
    else
    {
        return 1;
    } 
    
}


void enqueueReady(struct pcb *newPCB)
{
    struct pcb *temp;
    
 
     if(isEmptyReady()) // if the queue is empty
     {
         readyq->front = newPCB;
         newPCB->previous_PCB = readyq->front;
          readyq->rear = newPCB;
         newPCB->next_PCB = readyq->rear;
        // temp = q->front;
     }

    else if(newPCB-> priority > readyq->front->priority)
    {
        //printf("temp->priority %d.\n", temp->priority);
        newPCB->next_PCB = readyq->front;
        readyq->front = newPCB;
        newPCB->previous_PCB = readyq->front;
        newPCB->next_PCB->previous_PCB = newPCB; 
    }
     else
           temp = readyq->front;
        {
         while(!(newPCB->priority > temp->priority) && (temp != readyq->rear))
            {
                printf("enqueueReady priority %d \n", temp->priority);
             temp = temp->next_PCB;
            }

        if(newPCB->priority > temp->priority)
        {
            newPCB->next_PCB = temp;
            newPCB->previous_PCB = temp->previous_PCB;
            temp->previous_PCB = newPCB;
           // temp = temp->previous_PCB;
           temp = newPCB->previous_PCB;
           temp->next_PCB = newPCB;
            
        }

        else
        {
                newPCB->previous_PCB = temp;
                temp->next_PCB = newPCB;
                 readyq->rear = newPCB;
                newPCB->next_PCB = readyq->rear;
        }
        
         
     }

     readyq->count++;
     free(temp);
}


//dequeue
void dequeueReady()
{
    struct pcb *temp = readyq->front;

    //dequeue from front
    readyq->front = temp->next_PCB;
    temp->next_PCB->previous_PCB = readyq->front;
    printf("process successfully removed from Ready queue\n");  
    readyq->count--;

    free(temp);
}

int removeReady(struct pcb *deleteMe)
{
    struct pcb *temp;

    temp = readyq->front;

    if(temp == deleteMe)
    {
        readyq->front = temp->next_PCB; 
        temp->next_PCB->previous_PCB = readyq->front;
         printf("process successfully removed from Ready queue\n");
         
        readyq->count--;
        return 1;
        //free(temp->pid);
       
    }

    else
    {
            while(temp != deleteMe && temp->next_PCB != readyq->rear)
            {
                temp = temp->next_PCB;
            }
        if(temp == deleteMe)
        {
         temp->previous_PCB->next_PCB = temp->next_PCB;
         temp->next_PCB->previous_PCB = temp->previous_PCB;      
         readyq->count--;
         printf("process successfully removed from Ready queue\n");
         return 1;      
        }
        else
        {
            return 0;
             // printf("process not found\n");
        }      
    }

     free(temp);
}

//void traverse
struct pcb* checkReadyPCB(char *pname)
{
       char *tempstr = (char *) malloc(sizeof(char) * 32);
        struct pcb *temp;// = (struct pcb *) malloc(sizeof(struct pcb));;
        temp = readyq->front;
    printf("count-> %d\n", readyq->count);
    if(temp != NULL)
    {
         strcpy(tempstr, readyq->front->pid);
       // strcpy(tempstr,temp->pid);
     printf("This is string in temp->pid %s\n", tempstr);
   
    int compare = strcmp(pname, tempstr); // returns 0 is they are equal
    printf("%s\n", temp->pid);
    printf(" compare : %d\n", compare);
    printf("log1.2\n");

        while( compare != 0 && temp != readyq->rear)
        {
            printf("log1.3\n");
            compare = strcmp(pname, temp->pid);
               
                 printf("log1.3.1\n");
            temp =  temp -> next_PCB;
             printf("log1.4\n");

        }
                printf("log1.5\n");

            compare = strcmp(pname, temp->pid);


         if( compare == 0 )
        {
            return temp; // PCB of given pid exist
        }
    }

        return NULL;

}

void traverseReady()
{
    struct pcb *temp = readyq->front;

    while(temp != readyq->rear)
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
    free(temp);
}