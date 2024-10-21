#include <stdlib.h>    // for exit
#include <sys/types.h> // for pid_t (optional, used in some systems for fork return type)
#include <unistd.h>    // for fork
#include <stdio.h>     // for printf
#include <sys/wait.h>  // for waitpid

int N_CHILDREN(int n)
{
    pid_t last_child_pid;

    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork(); 
        if (pid == 0)
        {
            printf("Child %d created with PID: %d\n", i, getpid());
            exit(i);  
        }
        else if (pid > 0)
        {
            last_child_pid = pid; // record the last one
        }
    }

    int status;
    waitpid(last_child_pid, &status, 0); 
    printf("Last child with PID %d terminated with status %d\n", last_child_pid, WEXITSTATUS(status));

    return 0;
}

int main(int argc, char *argv[])
{
    N_CHILDREN(3);
}
