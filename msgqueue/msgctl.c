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

    int msgid2 = msgget(1234, 0); // open queue
    printf("msgid2 = %d", msgid2);
    struct msqid_ds buf;
    //msgctl(msgid2, IPC_RMID, NULL);
    msgctl(msgid2, IPC_STAT, &buf);
    printf("msgqunum = %d\n", buf.msg_qnum);
    sscanf("600","%o", (unsigned int)buf.msg_perm.mode);
    msgctl(msgid2, IPC_SET, &buf);
    return 0;
}
