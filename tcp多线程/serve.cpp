#include"socket.hpp"
#include<pthread.h>


void* ThreadStart(void* arg)
{
	pthread_detach(pthread_self());
	socket_tcp* sock = (socket_tcp*)arg;
	while(1)
	{
		string buf;
		sock->Recv(&buf);
		cout << "client say : " << buf << endl;
		cout << "serve  say : ";
		cin >> buf;
		sock->Send(buf);
	}
	sock->Close();
	delete sock;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "start serve : ./serve [ip] [port]" << endl;
		return 0;
	}

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
		socket_tcp* newsock = new socket_tcp();
		struct sockaddr_in peeraddr;
		if(!sock.Accept(&peeraddr,newsock))
		{
			continue;
		}
		cout << "newsock ip = " << inet_ntoa(peeraddr.sin_addr) << ", port = " << ntohs(peeraddr.sin_port) << endl;;
		
		pthread_t tid;
		int ret = pthread_create(&tid, NULL, ThreadStart, (void*)newsock);
		if(ret < 0)
		{
			perror("pthread_create");
			return 0;
		}		
	}
	return 0;
}
