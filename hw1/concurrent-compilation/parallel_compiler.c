#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s file1.c file2.c ...\n", argv[0]);
        exit(1);
    }

    int i;
    pid_t pid;
    char *object_files[argc - 1];

    for (i = 1; i < argc; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            char obj_file[256];
            snprintf(obj_file, sizeof(obj_file), "%s.o", argv[i]);

            // 执行 gcc -c file.c
            execlp("gcc", "gcc", "-c", argv[i], "-o", obj_file, (char *)NULL);
            perror("execlp failed");
            exit(1);
        }
        else if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        object_files[i - 1] = (char *)malloc(256 * sizeof(char));
        snprintf(object_files[i - 1], 256, "%s.o", argv[i]);
    }

    for (i = 1; i < argc; i++)
    {
        wait(NULL);
    }

    pid = fork();
    if (pid == 0)
    {
        char *gcc_args[argc + 2];
        gcc_args[0] = "gcc";
        for (i = 0; i < argc - 1; i++)
        {
            gcc_args[i + 1] = object_files[i];
        }
        gcc_args[argc] = "-o";
        gcc_args[argc + 1] = "output";
        gcc_args[argc + 2] = NULL;

        // run gcc link
        execvp("gcc", gcc_args);
        perror("execvp failed");
        exit(1);
    }
    else if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    wait(NULL);

    for (i = 0; i < argc - 1; i++)
    {
        free(object_files[i]);
    }

    printf("Compilation and linking completed. Executable created: output\n");

    return 0;
}
