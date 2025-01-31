#include<unistd.h>
#include<stdio.h>

#include <sys/types.h>
#include <sys/wait.h>

void main() {
	pid_t forked_pid = fork();
	
	if (forked_pid != 0) {
		printf("-------------------------------------\n");
		printf("This is the parent process\n");
		printf("Returned pid = %d\n", forked_pid);
		printf("Process pid  = %d\n", getpid());
		printf("Waiting for the child process to exit\n");
		printf("-------------------------------------\n\n");
		
		wait(&forked_pid);
		printf("\nChild process has exited\n");
		
	} else {
		printf("-------------------------------------\n");
		printf("This is the child process\n");
		printf("Returned pid = %d\n", forked_pid);
		printf("Process pid  = %d\n", getpid());
		printf("-------------------------------------\n");
	}
}
