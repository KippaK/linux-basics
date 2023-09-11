#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
	// ls path = /bin/ls
	char *path = "/bin/ls";
	int args_to_copy = argc - 2;
	if (argc < 3) { args_to_copy = 1; }
	char **ls_argv = (char**)malloc(args_to_copy * sizeof(char*));
	if (argc < 3) { ls_argv[0] = NULL; }
	else {
		for (int i = 0; i < argc - 2; i++) {
			ls_argv[i] = argv[i+2];
		}
	}
	char **ls_envp = { NULL };

	pid_t child_pid = fork();
	if (child_pid == -1) {
		perror("fork failed");
		exit(1);
	}
	if (child_pid == 0) {
		execve(argv[1], ls_argv, NULL);
		perror("execve failed");
		exit(1);
	}
	else {
		int status;
		waitpid(child_pid, &status, 0);
	}


	return 0;
}
