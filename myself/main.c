// main.c
#include <stdio.h>
#include "myio.h" // 引入自定义头文件

int main()
{
    const char *filename = "output.txt";
    const char *content = "\n\n\n\n\nHello, World!";

    // 读取并打印文件的原始内容
    printf("Original file content:\n");
    read_from_file(filename);

    // 调用自定义函数写入文件
    write_to_file(filename, content);

    printf("\nContent written to %s\n", filename);

    return 0;
}
