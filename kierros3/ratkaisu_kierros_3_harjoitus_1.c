#include <stdio.h>

int main(int argc, char** argv)
{
	printf("Komentoriviargumentteja: %d kpl\n", argc - 1);
	printf("Ja ne ovat:\n");
	for (int i = 1; i < argc; i++) {
		printf("\t%s\n", argv[i]);
	}
	return 0;
}
