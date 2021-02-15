#include "GameServer.h"
#include "Connection.h"
#include "Util.h"

GameServer::GameServer(HINSTANCE hInstance, int nCmdShow)
    : Window(hInstance, nCmdShow)
	, mConnectionPool(MAX_CCU)
	, mConnections {}
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
	RegisterUserMessage(std::bind(&GameServer::ProcessMessage, this, std::placeholders::_1, std::placeholders::_2));
	
	Window::Run();
}

void GameServer::ProcessMessage(WPARAM wParam, LPARAM lParam)
{
	switch (WSAGETSELECTEVENT(lParam))
	{
	case FD_ACCEPT:
		Util::GetInstance().PrintLog(L"Accept New Client!!!!!!");
	}
}