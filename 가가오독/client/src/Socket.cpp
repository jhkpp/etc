#include "Socket.h"

Socket::Socket(void)
{

}

Socket::~Socket(void)
{

}

int Socket::Init(char *sip, int port)
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in csa;
	csa.sin_family = AF_INET;
	csa.sin_addr.s_addr = inet_addr(sip);
	csa.sin_port = htons(port);

	int res = connect(s, (SOCKADDR*)&csa, sizeof(csa));


	closesocket(s);
	WSACleanup();

	return 0;
}