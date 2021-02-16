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

private:
	Socket mSocket;
};

