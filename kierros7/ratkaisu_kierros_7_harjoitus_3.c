#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int silent = 0;

    if (argc > 1 && strcmp(argv[1], "-s") == 0) {
        silent = 1;
    }
    const int arraySize = 100000000;
    int* array = (int*)malloc(arraySize * sizeof(int));
    if (array == NULL) {
        printf("Taulukon alustus epäonnistui.\n");
        return 1;
    }
    for (int i = 0; i < arraySize; ++i) {
        array[i] = i;
    }
    if (!silent) {
        printf("Taulukon sadan viimeisen alkion indeksit ja sisällöt:\n");
        for (int i = arraySize - 100; i < arraySize; ++i) {
            printf("Indeksi %d: %d\n", i, array[i]);
        }
    }
    free(array);
    return 0;
}
