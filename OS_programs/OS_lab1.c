/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h> // printf()
#include<stdlib.h> // exit()
#include<sys/types.h> // pid_t
#include<sys/wait.h> // wait()
#include<unistd.h> // fork
int main(int argc, char **argv)
{
	pid_t pid;
	pid = fork();
	if(pid==0)
	{
		printf("It is the child process and pid is %d\n",getpid());
		int i=0;
		for(i=0; i<8; i++)
		{
			printf("%d\n",i);
		}
		exit(0);
	}
	else if(pid > 0)
	{
		printf("It is the parent process and pid is %d\n",getpid());
		int status;
		wait(&status);
		printf("Child is repeated\n");
	}
	else
	{
		printf("Error in forking..\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}