#pragma once
#include "CommonLibrary.h"
#include "Window.h"
#include "Acceptor.h"
#include "ConnectionPool.h"

class Connection;

class GameServer : public Window
{
public:
	GameServer(HINSTANCE hInstance, int nCmdShow);
	~GameServer();

	bool Listen();	
	void Run() override;	

protected:
	virtual void OnConnect(Connection* connection) = 0;
	virtual void OnDisconnect(Connection* connection) = 0;
	virtual void OnReceive(Connection* connection) = 0;

private:	
	void ProcessMessage(WPARAM wParam, LPARAM lParam);
	void AcceptNewConnection(SOCKET sock);
	void Receive(SOCKET sock);

	ConnectionPool mConnectionPool;
	Acceptor mAcceptor;
	std::vector<Connection*> mConnections;		//활성화된 커넥션 모임
};