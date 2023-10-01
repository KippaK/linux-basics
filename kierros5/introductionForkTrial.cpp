#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <string.h>

#include <iostream>
using namespace std;

#define TRUE 1

void type_prompt();
void read_command(string &cmd, char **params);

int main(int argc, char *argv[], char *envp[])
{
  int status;
  string command;
  char *parameters[10];
  
  while (TRUE) {
      type_prompt();
      read_command(command, parameters);

      if (command.length() == 0)
	break;
      
      if (fork() != 0) {
	/* Parent code. */
	waitpid(-1, &status, 0);
      }
      else
      {
	/* Child code. */
	parameters[0] = (char *)(command.c_str());

	if (execve(command.c_str(), parameters, envp) == -1) {
	  cerr << "ERROR: errno = " << errno << endl;
	}
      }
  }
}

void type_prompt()
{
  cout << "Command: ";
}

void read_command(string &cmd, char **params)
{
  string input;
  
  getline(cin, cmd);

  if (cmd.length() == 0)
    return;
  
  int i = 1;

  do
    {
      cout << "Parameter (empty input means end of parameters): ";
      getline(cin, input);

      if (input.length() > 0) {
	params[i] = new char[strlen(input.c_str()) + 1];
	strcpy(params[i++], input.c_str());
      }
      else {
	params[i++] = NULL;
      }
    }
  while (input.length() > 0);
}
