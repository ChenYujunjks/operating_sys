#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // 解决 wait() 函数的隐式声明问题

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
        // 子进程执行新程序
        execlp("/bin/ls", "ls", NULL);
        // 如果execlp失败，以下代码会执行
        perror("execlp failed");
        return 1;
    }
    else
    {
        // 父进程等待子进程结束
        wait(NULL);
        printf("Child process has finished.\n");
    }

    return 0;
}
