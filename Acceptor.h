#pragma once
#include "CommonLibrary.h"
#include "Socket.h"

class Connection;
class ConnectionPool;

class Acceptor
{
public:
	Acceptor(ConnectionPool& pool);
	~Acceptor();
	
	bool Listen();
	void Run();

	Connection* Accept();
private:	
	ConnectionPool& mPool;
	Socket mListenSocket;	
};