#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("Invalid arguments\n");
		printf("Usage: %s <your_name>\n",argv[0]);
		return 1;
	}
	printf("Hello %s!\n", argv[1]);
	return 0;
}
