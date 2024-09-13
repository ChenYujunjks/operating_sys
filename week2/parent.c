#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // 调用 fork() 创建子进程
    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程
        printf("This is the child process. My PID is %d\n", getpid());
        printf("Child: My parent's PID is %d\n", getppid());
    }
    else
    {
        // 父进程
        printf("This is the parent process. My PID is %d\n", getpid());
        printf("GrandParent: My grandparent's PID is %d\n", getppid());
        printf("Parent: My child's PID is %d\n", pid);
    }

    return 0;
}
