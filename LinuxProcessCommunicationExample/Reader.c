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

    msgrcv(msgId, &message, sizeof(message), 1, 0);

    printf("Message received: %s\n", message.msg);

    msgctl(msgId, IPC_RMID, NULL);

    return 0;
}
