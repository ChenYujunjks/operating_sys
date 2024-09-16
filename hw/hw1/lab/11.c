#include <stdlib.h>    // for exit
#include <sys/types.h> // for pid_t (optional, used in some systems for fork return type)
#include <unistd.h>    // for fork
#include <stdio.h>     // for printf

int N_CHILDREN(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        if (fork() == 0)
        {
            printf("this is N time");
            exit(0);
        }
        else
        {
            N_CHILDREN(n - 1);
        }
    }
}
int main(int argc, char *argv[])
{
    N_CHILDREN(3);
}
