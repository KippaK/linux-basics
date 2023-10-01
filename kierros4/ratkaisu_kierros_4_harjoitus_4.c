#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

void print_errno(char *perror_str)
{
	perror(perror_str);
	printf("Errno: %d\n", errno);
	printf("Errno description: %s\n", strerror(errno));
}

int main() {
    FILE *file;
	char *file_name = "unknown_file.txt";
    file = fopen(file_name, "rb");

    if (file == NULL) {
		print_errno("Error opening file");
		exit(1);
	}
	char byte;
	size_t ret = fread(&byte, sizeof(char), 1, file);
	if (ret != 1) {
		print_errno("Error reading file");
		fclose(file);
		exit(1);
	}
	printf("Byte in file: %c\n", byte);
	fclose(file);

    return 0;
}
