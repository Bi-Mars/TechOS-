#ifndef PCB_H
#define PCB_H
struct pcb
{
    char *pid; // holds the name of the process
    unsigned int pclass; //identifies the process as system or application process
    unsigned int priority; // integer from 0-9
    unsigned int state_rrb; // 0 for ready, 1 for running, 2 for blocked
    unsigned int suspend; // 0 for not-suspended 1 for suspended 
    struct pcb *previous_PCB; // holds pointer to previous PCB struct
    struct pcb *next_PCB; //  holds pointer to next PCB struct
};

#endif