#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
	// ls path = /bin/ls
	char *path = "/bin/ls";
	char **ls_argv = { NULL };
	char **ls_envp = { NULL };
	
	pid_t child_pid = fork();
	if (child_pid == -1) {
		perror("fork failed");
		exit(1);
	}
	if (child_pid == 0) {
		char *args[] = {"/bin/ls", NULL};
		execve("/bin/ls", args, NULL);
		perror("execve failed");
		exit(1);
	}
	else {
		int status;
		waitpid(child_pid, &status, 0);
	}


	return 0;
}
