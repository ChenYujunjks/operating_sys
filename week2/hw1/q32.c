#include <stdlib.h>    // for exit
#include <sys/types.h> // for pid_t (optional, used in some systems for fork return type)
#include <unistd.h>    // for fork

int main(int argc, char *argv[])
{
    for (int i = 0; i < 3; i++)
    {
        if (fork() != 0)
        {
            if (i == 0)
            {
                wait(NULL);
            }
            exit(0);
        }
    }
    return 0;
}
