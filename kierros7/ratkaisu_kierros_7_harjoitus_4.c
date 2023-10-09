#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define ARRAY_SIZE 100000000 // Sadan miljoonan alkion koko
#define NUM_THREADS 10       // Säikeiden lukumäärä

int* array = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* fillArray(void* arg) {
    int threadIndex = *((int*)arg);
    int startIndex = threadIndex * (ARRAY_SIZE / NUM_THREADS);
    int endIndex = (threadIndex + 1) * (ARRAY_SIZE / NUM_THREADS);

    for (int i = startIndex; i < endIndex; ++i) {
        array[i] = i;
    }

    return NULL;
}

int main(int argc, char **argv) {
	int silent = 0;
	if (argc > 1 && strcmp(argv[1], "-s") == 0) {
        silent = 1;
    }

	array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Muistin varaaminen epäonnistui.\n");
        return 1;
    }

    pthread_t threads[NUM_THREADS];
    int threadIndices[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        threadIndices[i] = i;
        pthread_create(&threads[i], NULL, fillArray, &threadIndices[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    if (!silent) {
        printf("Taulukon sadan viimeisen alkion indeksit ja sisällöt:\n");
        for (int i = ARRAY_SIZE - 100; i < ARRAY_SIZE; ++i) {
            printf("Indeksi %d: %d\n", i, array[i]);
        }
    }
 
    free(array);
    return 0;
}
