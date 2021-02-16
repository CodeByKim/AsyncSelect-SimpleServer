#pragma once
#include "CommonLibrary.h"
#include "Socket.h"

class Connection
{
public:
	Connection();
	~Connection();

	void Initialize(SOCKET sock, SOCKADDR_IN addr);
	void Release();

	int Receive(char* buffer);
	int Send(char* buffer, int size);

	SOCKET GetSocketHandle();
private:
	Socket mSocket;
};

