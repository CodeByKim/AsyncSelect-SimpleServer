#pragma once
#include "CommonLibrary.h"

enum class ePacketNumber
{
	AssignId = 0,
	CreateStar,
	RemoveStar,
	MoveStar
};

// 헤더 : 4바이트 (추후 8바이트)
struct PacketHeader
{
	int protocol;
	//int length;
};

class Packet
{
public:
	virtual void Serialize(char* outBuffer) = 0;
	virtual void Deserialize(char* buffer) = 0;	

	PacketHeader header;
};

class AssignIdPacket : public Packet
{
public:
	AssignIdPacket();
	~AssignIdPacket();

	void Serialize(char* outBuffer) override;
	void Deserialize(char* buffer) override;

	int id;
};

class CreateStarPacket : public Packet
{
public:
	CreateStarPacket();
	~CreateStarPacket();

	void Serialize(char* outBuffer) override;
	void Deserialize(char* buffer) override;

	int id;
	int x;
	int y;
};

class RemoveStarPacket : public Packet
{
public:
	RemoveStarPacket();
	~RemoveStarPacket();

	void Serialize(char* outBuffer) override;
	void Deserialize(char* buffer) override;

	int id;
};

class MoveStarPacket : public Packet
{
public:
	MoveStarPacket();
	~MoveStarPacket();

	void Serialize(char* outBuffer) override;
	void Deserialize(char* buffer) override;

	int id;
	int x;
	int y;
};