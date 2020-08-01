#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string>
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


using namespace std;

class socket_tcp
{
	public:
		socket_tcp()
		{
			sockfd = -1;
		}
	public:
		//创建套接字
		bool Createsocket()
		{
			sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if(sockfd < 0)
			{
				perror("socket");
				return false;
			}
			return true;
		}
		//绑定地址信息
		bool Bind(string& ip, uint16_t port)
		{
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port);
			addr.sin_addr.s_addr = inet_addr(ip.c_str());
			int flag = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
			if(flag < 0)
			{
				perror("bind");
				return false;
			}
			return true;
		}
		//帧听
		bool Listen(int backlog = 5)
		{
			int flag = listen(sockfd, backlog);
			if(flag < 0)
			{
				perror("listen");
				return false;
			}
			return true;
		}
		//获取连接
		//bool Accept(struct sockaddr_in* peeraddr, int *servefd)
		//servefd为对象，接受新创建的套接字描述符，调用者直接使用该对象收发数据
		bool Accept(struct sockaddr_in* peeraddr, socket_tcp* servefd)
		{
			socklen_t addrlen = sizeof(struct sockaddr_in);
			int temp = accept(sockfd, (struct sockaddr*)peeraddr, &addrlen);
			if(temp < 0 )
			{
				perror("accept");
				return false;
			}
			servefd->sockfd = temp;
			return true;
		}
		//发起连接
		bool Connect(string& ip, uint16_t port)
		{
			struct sockaddr_in destaddr;
			destaddr.sin_family = AF_INET;
			destaddr.sin_port = htons(port);
			destaddr.sin_addr.s_addr = inet_addr(ip.c_str());
			int temp = connect(sockfd, (struct sockaddr*)&destaddr, sizeof(destaddr));
			if(temp < 0)
			{
				perror("connect");
				return false;
			}
			return true;
		}
		//发送数据
		bool Send(string& buf)
		{
			int flag = send(sockfd, buf.c_str(), buf.size(), 0);
			if(flag < 0)
			{
				perror("send");
				return false;
			}
			return true;
		}
		//接受数据
		bool Recv(string* buf)
		{
			char temp[1024] = {0};
			int flag = recv(sockfd, temp, sizeof(temp) - 1, 0);
			if(flag < 0 )
			{
				perror("recv");
				return false;
			}
			else if(flag == 0)
			{
				cout << "peer shutdown connect" << endl;
				return false;
			}
			else
			{
				(*buf).assign(temp, flag);
				return true;
			}
		}
		//关闭套接字
		void Close()
		{
			close(sockfd);
			sockfd = -1;
		}
		
	private:
		int sockfd;
};





