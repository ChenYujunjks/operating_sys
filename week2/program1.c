#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // 创建一个子进程

    if (pid < 0)
    {
        // fork失败
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程部分
        printf("Child process: pid = %d, parent pid = %d\n", getpid(), getppid());
    }
    else
    {
        // 父进程部分
        printf("Parent process: pid = %d, child pid = %d\n", getpid(), pid);
        wait(NULL); // 父进程等待子进程结束
        printf("Child process has finished.\n");
    }

    return 0;
}
