#ifndef _socket_HPP_
#define _socket_HPP_

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

using namespace std;

class socket_inter
{
public:
	socket_inter()
	{
		sockfd = -1;
	}
	~socket_inter()
	{

	}
	bool Createsocket()
	{
		sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sockfd < 0)
		{
			perror("socket");
			return false;
		}
		return true;
	}
	bool Bind(string& ip, uint16_t port)
	{
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		if (flag < 0)
		{
			perror("bind");
			return false;
		}
		return true;
		bool Send(string& buf, sockaddr_in* destaddr)
		{
			if (flag < 0)
			{
				perror("sendto");
				return false;
			}
			return true;
		}

		//4.接受数据
		bool Recv(string* buf, sockaddr_in* srcaddr)
		{
			char temp[1024];
			memset(temp, '\0', sizeof(temp));
			socklen_t socklen = sizeof(struct sockaddr_in);
			if (flag < 0)
			{
				perror("recvfrom");
				return false;
			}
			(*buf).assign(temp, flag);
			return true;
		}
		//5.关闭套接字
		void Close()
		{
			close(sockfd);
			sockfd = -1;
		}

	private:
		int sockfd;
};



#endif  // _socket_HPP_
