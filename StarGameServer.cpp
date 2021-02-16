#include "StarGameServer.h"
#include "Util.h"
#include "Packet.h"
#include "Connection.h"

StarGameServer::StarGameServer(HINSTANCE hInstance, int nCmdShow)
	: GameServer(hInstance, nCmdShow)
	, mID(0)
{

}

StarGameServer::~StarGameServer()
{

}

void StarGameServer::OnConnect(Connection* connection)
{
	Util::GetInstance().PrintLog(L"OnConnect...");

	AssignIdPacket* packet1 = new AssignIdPacket();
	packet1->id = mID;
	connection->SendPacket(packet1);

	CreateStarPacket* packet2 = new CreateStarPacket();
	packet2->id = mID;
	packet2->x = 20;
	packet2->y = 10;
	connection->SendPacket(packet2);

	mID += 1;
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