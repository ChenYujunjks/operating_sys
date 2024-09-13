// 示例：父子进程通过管道通信
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);

    if (fork() == 0)
    {
        // 子进程：写数据到管道
        close(fd[0]);
        write(fd[1], "Hello from child", 16);
        close(fd[1]);
    }
    else
    {
        // 父进程：从管道中读取数据
        char buffer[20];
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
