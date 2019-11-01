extern int day, month, year;
void viewdate();
void version();
void viewtime();
void terminate();
void askDate();
void setdate();
void help();
void helpVersion();
void helpdate();
void helpSetdate();
void helptime();
void helpterminate();
void initialize(); //date.c
void createPCB(char *id, unsigned int pclass, unsigned int priority);
void deletePCB(char *id);
void blockPCB(char *id);
void unblockPCB(char *id);
void suspendPCB(char *id);
void resumePCB(char *id);
void setPriority(char *id, unsigned int priority);
void showPCB(char *id);
void showReadyProcess();
void showBlockedProcess();
void showAllProcess();





     


