#include <stdlib.h> // for exit
#include <stdio.h>
#include <unistd.h> // for fork

int main(int argc, char *argv[])
{
    if (fork() != 10)
    {
        printf("a\n");
    }

    return 0;
}
