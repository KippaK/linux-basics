#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main() {
    FILE *file;
    file = fopen("unknown_file.txt", "w");

    if (file == NULL) {
        perror("Error opening file");
        printf("Errno: %d\n", errno);
        printf("Errno description: %s\n", strerror(errno));
		exit(1);
	}

	printf("Enter a characher: ");
	char c = getchar();
	fprintf(file, "%c", c);
	fclose(file);

    return 0;
}
