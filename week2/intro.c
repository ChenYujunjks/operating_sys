#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        // 创建子进程失败
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程
        printf("This is the child process\n");
    }
    else
    {
        // 父进程
        wait(NULL); // 等待子进程结束
        printf("This is the parent process\n");
    }
    return 0;
}
