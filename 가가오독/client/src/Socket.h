#pragma once
#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h>


class Socket {
public:
	Socket(void);
	~Socket(void);

public:
	int Init(const char* sip, int port);

};