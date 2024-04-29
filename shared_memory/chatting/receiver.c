#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>


#define KEY 12345

struct message {
    long mtype;
    char mtext[100];
};

int main() {
    int msgid;
    struct message msg;

   

    // Get the message queue
    msgid = msgget(KEY, 0666 | IPC_CREAT);

    // Receiving message
    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    printf("Process 2: Received message - \"%s\"\n", msg.mtext);

    // Sending reply
    msg.mtype = 2;
    sprintf(msg.mtext, "Loud and Clear");
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Process 2: Sent reply - \"%s\"\n", msg.mtext);

    // Receiving acknowledgment
    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    printf("Process 2: Received acknowledgment - \"%s\"\n", msg.mtext);

    return 0;
}

















// In the msgrcv and msgsnd functions, you can use different flag values other than 0 to modify the behavior of the function calls. Here are some commonly used flag values:
// For msgrcv:

// IPC_NOWAIT: If this flag is set, the function will return immediately with an error if no message of the requested type is available in the message queue. This is useful when you don't want the process to block indefinitely waiting for a message.
// MSG_NOERROR: If this flag is set and the message being received is longer than the specified buffer size (sizeof(msg) in your case), the message will be truncated to fit the buffer, and no error will be reported.

// For msgsnd:

// IPC_NOWAIT: If this flag is set, the function will return immediately with an error if the message queue is full and cannot accept the new message at the moment. This is useful when you don't want the process to block indefinitely waiting for space in the message queue.

// You can also combine these flags using the bitwise OR operator (|). For example:
// cCopy codemsgrcv(msgid, &msg, sizeof(msg), 1, IPC_NOWAIT | MSG_NOERROR);