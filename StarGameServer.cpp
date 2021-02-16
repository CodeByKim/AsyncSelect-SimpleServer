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
	Util::GetInstance().PrintLog(L"OnConnect...");
}

void StarGameServer::OnDisconnect(Connection* connection)
{

}

void StarGameServer::OnReceive(Connection* connection)
{
	Util::GetInstance().PrintLog(L"OnReceive...");
}