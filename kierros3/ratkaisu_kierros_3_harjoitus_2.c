#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	// ls path = /bin/ls
	char *path = "/bin/ls";
	char **ls_argv = { NULL };
	char **ls_envp = { NULL };
	execve(path, ls_argv, ls_envp);
	return 0;
}
