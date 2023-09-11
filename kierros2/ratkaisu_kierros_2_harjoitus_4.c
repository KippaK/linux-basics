#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray;  
    int size = 10;      

    dynamicArray = (int *)malloc(size * sizeof(int));

    if (dynamicArray == NULL) {
        fprintf(stderr, "Muistin varaaminen epäonnistui\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i + 1;
    }

    printf("Taulukon sisältö:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    free(dynamicArray);

    return 0;
}
