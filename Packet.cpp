#include "Packet.h"
#include "Util.h"

AssignIdPacket::AssignIdPacket()
{
	header.protocol = (int)ePacketNumber::AssignId;
}

AssignIdPacket::~AssignIdPacket()
{
	Util::GetInstance().PrintLog(L"Delete AssignIdPacket");
}

void AssignIdPacket::Deserialize(char* buffer)
{
	CopyMemory(&header.protocol, buffer, 4);
	CopyMemory(&id, buffer + 4, 4);
}

CreateStarPacket::CreateStarPacket()
{
	header.protocol = (int)ePacketNumber::CreateStar;
}

CreateStarPacket::~CreateStarPacket()
{
	Util::GetInstance().PrintLog(L"Delete CreateStarPacket");
}

void CreateStarPacket::Deserialize(char* buffer)
{
	CopyMemory(buffer + 0, &header.protocol, 4);
	CopyMemory(buffer + 4, &id, 4);
	CopyMemory(buffer + 8, &x, 4);
	CopyMemory(buffer + 12, &y, 4);
}

RemoveStarPacket::RemoveStarPacket()
{
	header.protocol = (int)ePacketNumber::RemoveStar;
}

RemoveStarPacket::~RemoveStarPacket()
{
	Util::GetInstance().PrintLog(L"Delete RemoveStarPacket");
}

void RemoveStarPacket::Deserialize(char* buffer)
{
	CopyMemory(buffer + 0, &header.protocol, 4);
	CopyMemory(buffer + 4, &id, 4);
}

MoveStarPacket::MoveStarPacket()
{
	header.protocol = (int)ePacketNumber::MoveStar;
}

MoveStarPacket::~MoveStarPacket()
{
	Util::GetInstance().PrintLog(L"Delete MoveStarPacket");
}

void MoveStarPacket::Deserialize(char* buffer)
{
	CopyMemory(buffer + 0, &header.protocol, 4);
	CopyMemory(buffer + 4, &id, 4);
	CopyMemory(buffer + 8, &x, 4);
	CopyMemory(buffer + 12, &y, 4);
}