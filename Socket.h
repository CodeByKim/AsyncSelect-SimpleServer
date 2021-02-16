#pragma once

#include "CommonLibrary.h"

class Socket
{
public:
	Socket();
	~Socket();

	bool Create();
	bool Create(SOCKET sock, SOCKADDR_IN addr);
	bool Bind(const char* ip, unsigned short port);
	bool Listen();
	
	int Receive(char* buffer);
	int Send(char* buffer, int size);

	void SetNonblocking();
	SOCKET GetSocketHandle();

private:
	SOCKET mSocket;
	SOCKADDR_IN mAddr;
};

