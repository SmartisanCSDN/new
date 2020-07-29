#include"socket.hpp"

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Start Client : ./client [ip] [port]" << endl;
		return 0;
	}

	string ip = argv[1];
	uint16_t port = atoi(argv[2]);

	socket_tcp sock;
	if(!sock.Createsocket())
	{
		return 0;
	}

	if(!sock.Connect(ip, port))
	{
		return 0;
	}

	while(1)
	{
		cout << "client say : ";
		string buf;
		cin >> buf;
		sock.Send(buf);

		sock.Recv(&buf);
		cout << "serve  say : " << buf << endl;
	}
	sock.Close();
	return 0;
}
