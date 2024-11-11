#include <stdio.h>
#include <pthread.h>

void* calculate_square(void* arg) {
    int num = *(int*)arg;
    int square = num * num;
    printf("Square of %d is %d\n", num, square);
    return NULL;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        if (pthread_create(&threads[i], NULL, calculate_square, &numbers[i])) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("pthread_join");
            return 1;
        }
    }

    return 0;
}