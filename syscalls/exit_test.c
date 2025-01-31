#include<unistd.h>
#include<stdio.h>

void main() {
	printf("Exiting the process using _exit()");
	_exit(0);
}
