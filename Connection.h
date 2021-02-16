#pragma once

#include "CommonLibrary.h"
#include "Socket.h"

class Packet;

class Connection
{
public:
	Connection();
	~Connection();

	void Initialize(SOCKET sock, SOCKADDR_IN addr);
	void Release();

	int Receive();	
	void SendPacket(Packet* packet);
	bool GetPacket(std::queue<std::shared_ptr<Packet>>* packetQueue);

	SOCKET GetSocketHandle();

private:
	RingBuffer mRecvBuffer;
	RingBuffer mSendBuffer;

	Socket mSocket;
};