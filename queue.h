#include "pcb.h"

struct queue
{
    int count; // total number of PCB in given Queue
    struct pcb *front;
    struct pcb *rear;
};

void initializeReady();
void enqueueReady( struct pcb *readyPCB);
void dequeueReady();
int removeReady( struct pcb *readyPCB);
int isEmptyReady();
struct pcb* checkReadyPCB(char *pname);
void traverseReady();


void initializeBlock();
void enqueueBlock (struct pcb *readyPCB);
void dequeueBlock();
int removeBlock( struct pcb *readyPCB);
int isEmptyBlock();
struct pcb* checkBlockPCB(char *pname);
void traverseBlock();

void initializesuspendReady();
void enqueuesuspendReady (struct pcb *readyPCB);
void dequeuesuspendReady();
int removesuspendReady( struct pcb *readyPCB);
int isEmptysuspendReady();
struct pcb* checksuspendReady(char *pname);
void traversesuspendReady();

void initializesuspendBlock();
void enqueuesuspendBlock (struct pcb *readyPCB);
void dequeuesuspendBlock();
int removesuspendBlock( struct pcb *readyPCB);
int isEmptysuspendBlock();
struct pcb* checksuspendBlock(char *pname);
void traversesuspendBlock();