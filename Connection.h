#pragma once
#include "CommonLibrary.h"
#include "Socket.h"

class Connection
{
public:
	Connection();
	~Connection();

private:
	Socket mSocket;
};

