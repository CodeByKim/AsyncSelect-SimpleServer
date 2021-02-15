#include "GameServer.h"
#include "Connection.h"
#include "Util.h"

GameServer::GameServer(HINSTANCE hInstance, int nCmdShow)
    : Window(hInstance, nCmdShow)
	, mConnections { }
{		
	for (int i = 0; i < MAX_CCU; i++)
	{
		mConnections[i] = std::make_unique<Connection>();
	}
}

GameServer::~GameServer()
{
    WSACleanup();
}

bool GameServer::Listen()
{	
	return mAcceptor.Listen();
}