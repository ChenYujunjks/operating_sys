#include <stdlib.h>    // for exit
#include <sys/types.h> // for pid_t (optional, used in some systems for fork return type)
#include <unistd.h>    // for fork
#include <stdio.h>     // for printf// for fork

int N_CHILDREN(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (fork() == 0)
        {
            exit(i);
        }
        wait(NULL);
    }
    printf("this is testing");
    return 0;
}
int main(int argc, char *argv[])
{
    N_CHILDREN(3);
}
