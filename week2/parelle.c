#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void task(const char *name, int duration)
{
    printf("%s started (pid = %d)\n", name, getpid());
    sleep(duration);
    printf("%s completed\n", name);
}

int main()
{
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        // 子进程1执行任务
        task("Task 1", 2);
        return 0;
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        // 子进程2执行任务
        task("Task 2", 3);
        return 0;
    }

    // 父进程等待所有子进程结束
    wait(NULL);
    wait(NULL);
    printf("All tasks completed.\n");

    return 0;
}
