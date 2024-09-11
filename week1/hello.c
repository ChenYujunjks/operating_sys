#include <stdio.h>
#include "hello.h"
#define DEBUG 1

void printidkdkdk_hello() {
#ifdef DEBUG
    printf("Debug mode is on\n");
#endif
    printf("Hello, World!\n");
}
