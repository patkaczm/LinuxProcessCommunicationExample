#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgBuffer
{
    long msgType;
    char msg[1024];
} message;

int main()
{
    key_t key;
    int msgId;


    key = ftok("coma", 65);
    msgId = msgget(key, 0666 | IPC_CREAT);

    message.msgType = 1;
    gets(message.msg);

    msgsnd(msgId, &message, sizeof(message), 0);

    printf("Send message: %s\n", message.msg);

    return 0;
}
