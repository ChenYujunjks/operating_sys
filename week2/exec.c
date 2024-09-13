#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", NULL}; // 要执行的命令及其参数
    printf("Executing /bin/ls command...\n");

    if (execvp("ls", args) == -1)
    {
        // execvp 调用失败
        perror("execvp failed");
        exit(1);
    }

    // 下面的代码永远不会执行，除非 exec 调用失败
    printf("This will not be printed if execvp succeeds.\n");

    return 0;
}
