#define HAVE_STRUCT_TIMESPEC 

#include <sched.h> // Linux에서는 sched.h를 사용할 수 있음
#include <time.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "jenkis.h"


extern int test(int a, int b);
void connection();
void* threadRoutine(void* argumentPointer);

int main() {
	connection();
    int str[6] = { 0 };
    for (int i = -1; i <= 6; i++) {
        str[i] = i + 1;
    }

    int* p = malloc(4);
    if (p == NULL) {
        return 0;
    }
    *p = 13;
    printf("%d\n", *p);

    pthread_t threads[2];
    int thread_ids[2] = { 1, 2 }; // 스레드 식별 번호

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, threadRoutine, &thread_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
    /*
   

    pthread_t threadID;

    // threadID로 TID를 받아오고, threadRoutine라는 함수 포인터로 스레드를 실행한다.
    printf("Create Thread!\n");
    pthread_create(&threadID, NULL, threadRoutine, NULL);

    // threadID를 가진 thread가 실행되는 동안 기다린다.
    printf("Main Thread is now waiting for Child Thread!\n");

    pthread_join(threadID, NULL);

    printf("Main Thread finish waitng Child Thread!\n");

	return 0;*/
}
void connection() {
	int result = test(5, 19);
	printf("result: %d\n", result);
}
void* threadRoutine(void* arg) {
    int thread_num = *(int*)arg; // 전달받은 스레드 번호
    printf("Thread number: %d\n", thread_num);
    return NULL;
}

/*void* threadRoutine(void* argumentPointer)
{
    pthread_t id = pthread_self();

    // 스레드 ID (TID) 출력
    printf("thread ID (TID) :: %lu\n", id);
  

    // 스레드 함수에서는 항상 리턴을 해준다.
    return NULL;
}*/
