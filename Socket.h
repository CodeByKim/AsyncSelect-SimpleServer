#pragma once

#include "CommonLibrary.h"

class Socket
{
public:
	Socket();
	~Socket();

	bool Create();
	bool Bind(const char* ip, unsigned short port);
	bool Listen();
	
	void SetNonblocking();
	SOCKET GetSocketHandle();

private:
	SOCKET mSocket;
	SOCKADDR_IN mAddr;
};

