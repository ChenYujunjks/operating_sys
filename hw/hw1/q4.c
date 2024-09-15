#include <stdlib.h>    // for exit
#include <sys/types.h> // for pid_t (optional, used in some systems for fork return type)
#include <unistd.h>    // for fork

int main(int argc, char *argv[])
{
    if (fork() != 10)
    {
        printf(333);
    }

    return 0;
}
