#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork(); // 创建一个子进程

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程部分
        printf("Child process: pid = %d, parent pid = %d\n", getpid(), getppid());
        sleep(2); // 模拟子进程执行任务
        printf("Child process completed.\n");
    }
    else
    {
        // 父进程等待子进程结束
        int status;
        wait(&status); // wait返回子进程的结束状态
        if (WIFEXITED(status))
        {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
