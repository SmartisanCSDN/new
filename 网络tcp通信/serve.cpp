#include"socket.hpp"

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Start Serve : ./serve [ip] [port]" << endl;
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

	socket_tcp serve_sock;
	struct sockaddr_in clientaddr;
	if(!sock.Accept(&clientaddr, &serve_sock))
	{
		return 0;
	}

	while(1)
	{
		string buf;
		serve_sock.Recv(&buf);
		cout << "client say : " << buf << endl;

		cout << "serve  say : ";
		cin >> buf;
		serve_sock.Send(buf);
	}
	serve_sock.Close();
	sock.Close();
	return 0;
}

