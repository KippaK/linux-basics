#include <stdio.h>

int main(int argc, char** argv)
{
	int j = 2;
	if (j = 2) {
		for (int i = 0; i < 10; i++) {
			j++;
		}
	}
	if (argc != 2) {
		printf("Invalid arguments\n");
		printf("Usage: %s <your_name>\n",argv[0]);
		return 1;
	}
	printf("Hello %s!\n", argv[1]);
	return 0;
}
