#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



int main() {
    FILE *file;
    file = fopen("unknown_file.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        printf("Errno: %d\n", errno);
        printf("Errno description: %s\n", strerror(errno));
    } else {
        fclose(file);
    }

    return 0;
}
