#include<unistd.h>
#include<stdio.h>

void main() {
	pid_t cur_pid = getpid();
	printf("The pid of the current process is %d", cur_pid);
}
