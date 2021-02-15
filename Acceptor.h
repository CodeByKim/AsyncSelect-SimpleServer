#pragma once
#include "CommonLibrary.h"
#include "Socket.h"

class Acceptor
{
public:
	Acceptor();
	~Acceptor();
	
	bool Listen();
	void StartAccept();

private:	
	Socket mListenSocket;	
};