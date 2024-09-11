# 定义变量
CC=gcc
CFLAGS=-Wall -g
EXEC=hello

# 默认目标
all: $(EXEC)

# 可执行文件依赖于 hello.o 和 main.o
$(EXEC): hello.o main.o
	$(CC) -o $@ $^

# 编译 hello.o
hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c -o hello.o

# 编译 main.o
main.o: main.c hello.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# 清理
clean:
	rm -f *.o $(EXEC)
