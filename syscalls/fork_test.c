#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>

void main() {
	pid_t forked_pid = fork();
	
	if (forked_pid == 0) {
		printf("Hello World from child (returned pid = %d)\n", forked_pid);
	} else {
		printf("Hello World from parent (returned pid = %d)\n", forked_pid);
	}
}
