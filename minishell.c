//Elianys Ventura Rodriguez
//////Panther ID: 5652936
//////This is a program that creates two child processes and uses fork and pipes
//////“I affirm that I wrote this program myself without any help form any other people or sources from the internet.”.
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


char *cmd1[] = { "/bin/ls","-al", NULL};
char *cmd2[] = { "/bin/grep","minishell",NULL};

void run1(int pfd[]);
void run2(int pfd[]);

int
main(int argc, char **argv)

{   	//Initialization of vars, process id and status
	int pid, status;
	int fd[2];

	pipe(fd);

	run1(fd);//Runs 1s child process
	run2(fd);//Runs second child process
	close(fd[0]);//Closes the process 
	close(fd[1]); //Closes the process 
	
	//Lets the user know the process and how it exits
	while ((pid = wait(&status)) != -1) 
	{
	fprintf(stderr, "Process %d exits with %d\n", pid, status);
	}
	
	//Exits with 0	
	exit(0);
}

//Runs the first part of the pipeline which is cdm1, the first child
void run1(int pfd[])
{
	//Process id
	int pid;	

	switch (pid = fork()) 
	{
	
	//Child 1
	case 0: 
		dup2(pfd[1], 1);//This becomes the standard output
		close(pfd[0]);//Close the other end of the pipe
		execvp(cmd1[0], cmd1);//This runs the command
		perror(cmd1[0]);//Error if it fails

	//The parents doesnt do anything
	default: 
		break;
	//Error on the fork
	case -1:
		perror("fork");
		exit(1);
	}
}
//This runs the second part of the pipeline which is cdm2, the second child
void run2(int pfd[])	
{
	//Process id
	int pid;

	switch (pid = fork()) 
	{

	//Child 2
	case 0: 
		dup2(pfd[0], 0);//This becomes the standard input 
		close(pfd[1]);//Closes the other end of the pipe 
		execvp(cmd2[0], cmd2);//This runs the command 
		perror(cmd2[0]);//Error if it failed

	//The parent doesnt do anything
	default:  
		break;
	
	//Error on the fork
	case -1:
		perror("fork");
		exit(1);
	}
}
