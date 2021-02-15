#pragma once
#include "CommonLibrary.h"
#include "Socket.h"

class Connection
{
public:
	Connection();
	~Connection();

	void Initialize();
	void Release();

private:
	Socket mSocket;
};

