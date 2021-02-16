#include "Packet.h"
#include "Util.h"

#pragma region AssignIdPacket
AssignIdPacket::AssignIdPacket()
{
	header.protocol = (int)ePacketNumber::AssignId;
}

AssignIdPacket::~AssignIdPacket()
{
	Util::GetInstance().PrintLog(L"Delete AssignIdPacket");
}

void AssignIdPacket::Serialize(char* outBuffer)
{
	CopyMemory(outBuffer + 0, &header.protocol, 4);
	CopyMemory(outBuffer + 4, &id, 4);
}

void AssignIdPacket::Deserialize(char* buffer)
{
	CopyMemory(&header.protocol, buffer, 4);
	CopyMemory(&id, buffer + 4, 4);
}
#pragma endregion

#pragma region CreateStarPacket
CreateStarPacket::CreateStarPacket()
{
	header.protocol = (int)ePacketNumber::CreateStar;
}

CreateStarPacket::~CreateStarPacket()
{
	Util::GetInstance().PrintLog(L"Delete CreateStarPacket");
}

void CreateStarPacket::Serialize(char* outBuffer)
{
	CopyMemory(outBuffer + 0, &header.protocol, 4);
	CopyMemory(outBuffer + 4, &id, 4);
	CopyMemory(outBuffer + 8, &x, 4);
	CopyMemory(outBuffer + 12, &y, 4);
}

void CreateStarPacket::Deserialize(char* buffer)
{
	CopyMemory(&header.protocol, buffer + 0, 4);
	CopyMemory(&id, buffer + 4, 4);
	CopyMemory(&x, buffer, 8);
	CopyMemory(&y, buffer + 12, 4);
}
#pragma endregion

#pragma region RemoveStarPacket
RemoveStarPacket::RemoveStarPacket()
{
	header.protocol = (int)ePacketNumber::RemoveStar;
}

RemoveStarPacket::~RemoveStarPacket()
{
	Util::GetInstance().PrintLog(L"Delete RemoveStarPacket");
}

void RemoveStarPacket::Serialize(char* outBuffer)
{
	CopyMemory(outBuffer + 0, &header.protocol, 4);
	CopyMemory(outBuffer + 4, &id, 4);
}

void RemoveStarPacket::Deserialize(char* buffer)
{
	CopyMemory(&header.protocol, buffer, 4);
	CopyMemory(&id, buffer + 4, 4);
}
#pragma endregion

#pragma region MoveStarPacket
MoveStarPacket::MoveStarPacket()
{
	header.protocol = (int)ePacketNumber::MoveStar;
}

MoveStarPacket::~MoveStarPacket()
{
	Util::GetInstance().PrintLog(L"Delete MoveStarPacket");
}

void MoveStarPacket::Serialize(char* outBuffer)
{
	CopyMemory(outBuffer + 0, &header.protocol, 4);
	CopyMemory(outBuffer + 4, &id, 4);
	CopyMemory(outBuffer + 8, &x, 4);
	CopyMemory(outBuffer + 12, &y, 4);
}

void MoveStarPacket::Deserialize(char* buffer)
{
	CopyMemory(&header.protocol, buffer + 0, 4);
	CopyMemory(&id, buffer + 4, 4);
	CopyMemory(&x, buffer, 8);
	CopyMemory(&y, buffer + 12, 4);
}
#pragma endregion