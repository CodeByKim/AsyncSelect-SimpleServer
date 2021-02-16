#include "GameServer.h"
#include "Connection.h"
#include "Util.h"

GameServer::GameServer(HINSTANCE hInstance, int nCmdShow)
    : Window(hInstance, nCmdShow)
	, mConnectionPool(MAX_CCU)
	, mConnections {}
	, mAcceptor(mConnectionPool)
{		
	
}

GameServer::~GameServer()
{
    WSACleanup();
}

bool GameServer::Listen()
{	
	return mAcceptor.Listen();
}

void GameServer::Run()
{
	mAcceptor.StartAccept();	

	RegisterUserMessage(FD_ACCEPT, std::bind(&GameServer::AcceptNewConnection, this, std::placeholders::_1));
	RegisterUserMessage(FD_READ, std::bind(&GameServer::Receive, this, std::placeholders::_1));
	
	Window::Run();
}

void GameServer::AcceptNewConnection(SOCKET sock)
{		
	 Connection* connection = mAcceptor.Accept();
	 mConnections.push_back(connection);

	 OnConnect(connection);
}

void GameServer::Receive(SOCKET sock)
{

}