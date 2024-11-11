#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void *calculate_sum(void *arg){
    int start = *(int *)arg;
    int end = start + ARRAY_SIZE / 2;
    int sum = 0;

    for (int i = start; i < end; i++){
        sum += arr[i];
    }

    printf("Sum of the half: %d\n", sum);
    return NULL;
}

int main(){
    pthread_t thread1;
    pthread_t thread2;
    int thread1Arg = 0;
    int thread2Arg = ARRAY_SIZE / 2;

    if (pthread_create(&thread1, NULL, calculate_sum, &thread1Arg)){
        perror("pthread_create");
        return 1;
    }

    if (pthread_create(&thread2, NULL, calculate_sum, &thread2Arg)){
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

    return 0;
}