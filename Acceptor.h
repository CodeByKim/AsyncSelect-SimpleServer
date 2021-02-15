#pragma once
#include "CommonLibrary.h"
#include "Socket.h"

class Acceptor
{
public:
	Acceptor();
	~Acceptor();
	
	bool Listen();

private:	
	Socket mListenSocket;	
};