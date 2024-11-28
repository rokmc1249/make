# 컴파일러와 옵션
CC = gcc
CFLAGS = -Wall
LDFLAGS = -lpthreadVC1

# 실행 파일 이름
TARGET = test

# 소스 및 경로
SRCS = main.c sub.c
INC = prebuilt-dll-1-10-0-release\include
LIB = prebuilt-dll-1-10-0-release\lib

# 객체 파일 목록
OBJS = $(SRCS:.c=.o)

# 실행 파일 생성 규칙
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIB)

# 목적 파일 생성 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

# 정리 규칙
clean :
	del /f $(OBJS) $(TARGET)

.PHONY : clean


