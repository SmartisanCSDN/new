#include"socket.hpp"

int main(int argc, char* argv[])
{
	//./socket [ip] [port]
	if (argc != 3)
	{
		return 0;
	}
	string ip = argv[1];
	uint16_t port = atoi(argv[2]);

	socket_inter sock;

	if (!sock.Createsocket())
	{
		return 0;
	}

	if (!sock.Bind(ip, port))
	{
		return 0;
	}

	string buf;
	while (1)
	{
		//接收数据
		struct sockaddr_in srcaddr;
		sock.Recv(&buf, &srcaddr);

		cout << "client say : " << buf << endl;
		cout << "serve  say : ";
		cin >> buf;
		sock.Send(buf, &srcaddr);
	}

	sock.Close();
	return 0;
}
