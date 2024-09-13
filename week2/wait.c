#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // 创建子进程

    if (pid < 0)
    {
        // fork失败
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // 子进程执行的代码
        printf("Child process (PID: %d) running...\n", getpid());
        sleep(2); // 模拟子进程的工作
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0);
    }
    else
    {
        // 父进程执行的代码
        int status;
        printf("Parent process (PID: %d) waiting for child to finish...\n", getpid());
        wait(&status); // 阻塞父进程，等待子进程结束
        if (WIFEXITED(status))
        {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
        printf("Parent process (PID: %d) exiting...\n", getpid());
    }

    return 0;
}
