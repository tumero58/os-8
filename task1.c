#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg)
{
    int thread_id = *(int *)arg;
    printf("Thread %d is running\n", thread_id);
    return NULL;
}

int main()
{
    pthread_t thread1;
    int thread1Id = 1;
    pthread_t thread2;
    int thread2Id = 2;
    pthread_t thread3;
    int thread3Id = 3;

    if (pthread_create(&thread1, NULL, thread_func, &thread1Id)){
        perror("pthread_create");
        return 1;
    }
    if (pthread_create(&thread2, NULL, thread_func, &thread2Id)){
        perror("pthread_create");
        return 1;
    }
    if (pthread_create(&thread3, NULL, thread_func, &thread3Id)){
        perror("pthread_create");
        return 1;
    }

    if (pthread_join(thread1, NULL)){
        perror("pthread_join");
        return 1;
    }
    if (pthread_join(thread2, NULL)){
        perror("pthread_join");
        return 1;
    }
    if (pthread_join(thread3, NULL)){
        perror("pthread_join");
        return 1;
    }
    printf("All threads have finished.\n");
    return 0;
}