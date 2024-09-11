// myio.c
#include <stdio.h>
#include "myio.h"
#define DEBUG 1

void write_to_file(const char *filename, const char *content)
{
#ifdef DEBUG
    printf("Debug mode is on\n");
#endif
    FILE *file = fopen(filename, "a"); // 打开文件写入模式
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s", content); // 写入内容到文件
    fclose(file);                 // 关闭文件
}

// 读取并打印文件内容
void read_from_file(const char *filename)
{
    FILE *file = fopen(filename, "r"); // 以只读模式打开文件
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {                // 逐字符读取文件内容
        putchar(ch); // 打印字符到控制台
    }

    fclose(file); // 关闭文件
}

int std_learn()
{
    char name[50];
    printf("Enter your name: ");
    fgets(name, 50, stdin); // 从标准输入读取用户输入
    printf("Hello, %s", name);
    return 0;
}