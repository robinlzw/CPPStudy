#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	pid_t pid;
	if((pid=fork())==-1)
	{
		printf("fork error");
	}
	else if(pid==0)
	{	
		printf("child bye!\n");
	}
	else
	{
		printf("parent bye!\n");
	}
	return 0;
}
