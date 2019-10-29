struct pcb *allocatePCB(); // creates new PCB and returns pointer to newly created PCB
void freePCB(struct pcb *freeMe); // free all memory created by the given PCB. returns 1 if successful 
struct pcb *setupPCB(char *pid, unsigned int pClass, unsigned int pPriority); // calls allocatePCB() --> creates empty pcb, initalize PCB --> set PCB state to ready
struct pcb  *findPCB(char *pid);
void insertPCB(struct pcb *insertMe);
void removePCB(struct pcb *removeMe);