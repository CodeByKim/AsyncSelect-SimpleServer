#include "StarGameServer.h"
#include "Util.h"

StarGameServer::StarGameServer(HINSTANCE hInstance, int nCmdShow)
	: GameServer(hInstance, nCmdShow)
{

}

StarGameServer::~StarGameServer()
{

}

void StarGameServer::OnConnect(Connection* connection)
{
	if (connection != nullptr)
	{
		Util::GetInstance().PrintLog(L"Good...");
	}
}

void StarGameServer::OnDisconnect(Connection* connection)
{

}

void StarGameServer::OnReceive(Connection* connection)
{

}