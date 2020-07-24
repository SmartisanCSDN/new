#include"socket.hpp"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "./client [ip] [port]" << endl;
		return 0;
	}
	string serve_ip = argv[1];
	uint16_t serve_port = atoi(argv[2]);
	socket_inter sock;

	if (!sock.Createsocket())
	{
		return 0;
	}
	struct sockaddr_in destaddr;
	destaddr.sin_family = AF_INET;
	destaddr.sin_port = htons(serve_port);
	destaddr.sin_addr.s_addr = inet_addr(serve_ip.c_str());
	string buf;
	while (1)
	{
		//发送数据
		cout << "client say : ";
		cin >> buf;
		sock.Send(buf, &destaddr);
		//接受数据
		sock.Recv(&buf, &destaddr);
		cout << "serve  say : " << buf << endl;
	}
	sock.Close();
	return 0;
}
