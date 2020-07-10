#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void fun(int sig)
{
	printf("signo is %d\n", sig);
}

int main()
{
	signal(2, fun);
	signal(40, fun);

	sigset_t set, oldset;

	sigemptyset(&set);
	sigemptyset(&oldset);

	sigfillset(&set);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	getchar();
	sigprocmask(SIG_UNBLOCK, &set, NULL);

	while (1)
	{
		sleep(1);
	}

	return 0;
}

//struct sigaction oldact;
//void fun(int signo)
//{
//  printf("signo : %d\n", signo);
//  sigaction(2, &oldact, NULL);
//}
//
//int main()
//{
//  struct sigaction newact;
//  newact.sa_handler = fun;
//  sigemptyset(&newact.sa_mask);
//  newact.sa_flags = 0;
//  sigaction(2, &newact, &oldact);
//
//  while(1)
//  {
//      sleep(1);
//  }
//  return 0;
//}