#pragma once
#include "CommonLibrary.h"
#include "Window.h"
#include "Acceptor.h"

class Connection;

class GameServer : public Window
{
public:
	GameServer(HINSTANCE hInstance, int nCmdShow);
	~GameServer();

	bool Listen();	

protected:
	virtual void OnConnect(Connection* connection) = 0;
	virtual void OnDisconnect(Connection* connection) = 0;
	virtual void OnReceive(Connection* connection) = 0;

private:	
	std::unique_ptr<Connection> mConnections[MAX_CCU];
	Acceptor mAcceptor;
};

