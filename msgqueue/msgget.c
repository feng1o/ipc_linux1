#include"sys/types.h"
#include"sys/ipc.h"
#include"sys/msg.h"

#include"unistd.h"
#include"stdlib.h"
#include"stdio.h"
#include"errno.h"
#include"string.h"

#define ERR_EXIT(m) \ 
do \
{ \
perror(m); \
exit(EXIT_FAILURE); \
}  \
while (0)

int main(void){
    int msgid;
   //msgid = msgget(1234,0666 | IPC_CREAT ); //no 1234 key process; creat needed;
    msgid = msgget(IPC_PRIVATE,0400 | IPC_CREAT ); //private will let creat lots of process;
   // msgid = msgget(1234,0666 | IPC_CREAT | IPC_EXCL ); // EXCL and CREAT ;if 1234 is also created, will not creat again;
    if(-1 == msgid)
        ERR_EXIT("msgget");
    printf("msgget success\n");

    int msgid2 = msgget(1234, 0); // open queue
    printf("msgid2 = %d", msgid2);
    int msgid3 = msgget(1234, 0666); // open queue
    printf("msgid2 = %d", msgid3);
    return 0;
}
