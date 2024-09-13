// 示例：通过POSIX消息队列进行间接通信
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/types.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msg_id;

    // 创建消息队列
    key = ftok("progfile", 65);
    msg_id = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer message;

    // 接收消息
    msgrcv(msg_id, &message, sizeof(message), 1, 0);
    printf("Data received: %s\n", message.msg_text);

    // 删除消息队列
    msgctl(msg_id, IPC_RMID, NULL);
    return 0;
}
