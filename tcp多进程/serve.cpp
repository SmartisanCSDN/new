#include"socket.hpp"
#include<sys/wait.h>


void sigcb(int signo)
{
	(void)signo;
	while(1)
	{
		waitpid(-1, NULL, WNOHANG);
	}
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "start serve : ./serve [ip] [port]" << endl;
		return 0;
	}

	signal(SIGCHLD, sigcb);

	string ip = argv[1];
	uint16_t port = atoi(argv[2]);

	socket_tcp sock;

	if(!sock.Createsocket())
	{
		return 0;
	}

	if(!sock.Bind(ip, port))
	{
		return 0;
	}

	if(!sock.Listen())
	{
		return 0;
	}

	while(1)
	{
		socket_tcp newsock;
		struct sockaddr_in peeraddr;
		if(!sock.Accept(&peeraddr,&newsock))
		{
			continue;
		}
		cout << "newsock ip = " << inet_ntoa(peeraddr.sin_addr) << ", port = " << ntohs(peeraddr.sin_port) << endl;;
		

		int pid = fork();
		if(pid < 0)
		{
			perror("fork");
		}
		else if(pid == 0)
		{
			//子进程
			while(1)
			{
				string buf;
				newsock.Recv(&buf);
				cout << "client say : " << buf << endl;
				cout << "serve  say : ";
				
				cin >> buf;
				newsock.Send(buf);
			}
			newsock.Close();
			exit(1);
		}
		else
		{
			//父进程
			newsock.Close();
		}
	}

	return 0;
}
