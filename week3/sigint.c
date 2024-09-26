#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// 定义中断处理程序
void handle_interrupt(int sig) {
    printf("收到信号 %d: 中断已捕捉到!\n", sig);
    exit(0);  
}

int main() {
    // 设置中断处理程序，当收到 SIGINT 信号时调用 handle_interrupt 函数
    signal(SIGINT, handle_interrupt);

    printf("正在等待中断信号，按 Ctrl+C 发送 SIGINT...\n");

    // 无限循环，让程序持续运行，等待中断信号
    while (1) {
        printf("程序运行中...\n");
        sleep(1);  // 每秒暂停一次
    }

    return 0;
}
