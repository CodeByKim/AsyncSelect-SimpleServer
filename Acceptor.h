#pragma once
#include "CommonLibrary.h"

class Acceptor
{
public:
	Acceptor();
	~Acceptor();

	void Initialize();
	bool Listen();

private:
	void SetNonblockingSocket(SOCKET socket);

	SOCKET mListenSocket;
	SOCKADDR_IN mAddr;
};

