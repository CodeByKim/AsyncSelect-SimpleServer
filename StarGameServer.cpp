#include "StarGameServer.h"
#include "Util.h"
#include "Packet.h"

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

void StarGameServer::OnReceive(Connection* connection, Packet* packet)
{
	int proto = packet->header.protocol;

	switch (proto)
	{
	case (int)ePacketNumber::AssignId:
		Util::GetInstance().PrintLog(L"On Receive AssignId Packet");
		break;
	case (int)ePacketNumber::CreateStar:
		Util::GetInstance().PrintLog(L"On Receive CreateStar Packet");
		break;
	case (int)ePacketNumber::RemoveStar:
		Util::GetInstance().PrintLog(L"On Receive RemoveStar Packet");
		break;
	case (int)ePacketNumber::MoveStar:
		Util::GetInstance().PrintLog(L"On Receive MoveStar Packet");
		break;
	}
}