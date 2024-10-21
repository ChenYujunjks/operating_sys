#include <stdio.h>     // for printf
#include <stdlib.h>    // for exit
#include <sys/types.h> // for pid_t (optional, used in some systems for fork return type)
#include <sys/wait.h>  // for wait and WEXITSTATUS
#include <unistd.h>    // for fork

int main(int argc, char *argv[])
{
    int a, e;
    a = 10;
    if (fork() == 0)
    {
        a = a * 2;
        if (fork() == 0)
        {
            a = a + 1;
            exit(2);
        }
        printf("%d \n", a);
        exit(a);
    }
    wait(&e);
    sleep(30);
    wait(&e);
    printf("a:%d; e:%d \n", a, WEXITSTATUS(e));
    return 0;
}
