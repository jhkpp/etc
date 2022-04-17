#include "Socket.h"

Socket::Socket(void)
{
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		return;
}

Socket::~Socket(void)
{
	WSACleanup();
}

int Socket::Init(const char *sip, int port)
{	
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
		return -1;

	sockaddr_in csa;
	csa.sin_family = AF_INET;
	csa.sin_addr.s_addr = inet_addr(sip);
	csa.sin_port = htons(port);

	if (connect(s, (SOCKADDR*)&csa, sizeof(csa)) == -1)
		return -1;

	closesocket(s);

	return 0;
}