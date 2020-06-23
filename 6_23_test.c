#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

//int main()
//{
//	printf("The program is begin\n");
//	int pid = fork();
//	if(pid < 0)
//	{
//		printf("error\n");
//	}
//	else if(pid == 0)
//	{
//		printf("I am child\n");
//		while(1)
//		{
//			printf("hello\n");
//			sleep(5);
//		}
//	}
//	else
//	{
//		printf("I am father\n");
//		sleep(20);
//	}
//	return 0;
//}
int main()
{
	printf("The program is begin\n");
	int pid = fork();
	if(pid < 0)
	{
		printf("error\n");
	}
	else if(pid == 0)
	{
		printf("I am child\n");
		sleep(5);
	}
	else
	{
		printf("I am father\n");
		int status = 0xff;
		wait(&status);
		printf("status = %d\n", status);
		printf("status & 0x7f = %d\n", status & 0x7f);
		printf("(status >> 7) & 0x1 = %d\n", (status >> 7) & 0x1);
		printf("(status >> 8) & 0xff = %d\n", (status >> 8) & 0xff);

	}
	return 0;
}
