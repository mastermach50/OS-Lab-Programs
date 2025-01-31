#include<unistd.h>
#include<stdio.h>

void main() {
	char *args[] = { "./helloworld", NULL};
	execvp(args[0], args);
}
