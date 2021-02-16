#include "Connection.h"
#include "Util.h"
#include "Packet.h"

Connection::Connection()
	: mRecvBuffer(BUFFER_SIZE)
	, mSendBuffer(BUFFER_SIZE)
{	
	//Initialize();
}

Connection::~Connection()
{	
	Release();
}

void Connection::Initialize(SOCKET sock, SOCKADDR_IN addr)
{
	if (!mSocket.Create(sock, addr))
	{
		Util::GetInstance().PrintError(L"Create Socket Error");
	}

	mSocket.SetNonblocking();
}

void Connection::Release()
{

}

int Connection::Receive()
{
	char buffer[BUFFER_SIZE];	
	int recvSize = mSocket.Receive(buffer, BUFFER_SIZE);
	mRecvBuffer.Enqueue(buffer, recvSize);

	return recvSize;
}

bool Connection::GetPacket(std::queue<std::shared_ptr<Packet>>* packetQueue)
{	
	while (true)
	{
		char buffer[PACKET_SIZE];
		if (mRecvBuffer.Peek(buffer, PACKET_SIZE))
		{			
			mRecvBuffer.MoveFront(PACKET_SIZE);

			//일단 그냥하고 나중에는 패킷 팩토리에 던져?
			int protocol = -1;
			CopyMemory(&protocol, buffer, sizeof(int));

			std::shared_ptr<Packet> packet = nullptr;
			switch (protocol)
			{
			case (int)ePacketNumber::AssignId:
				packet = std::make_shared<AssignIdPacket>();
				break;
			case (int)ePacketNumber::CreateStar:
				packet = std::make_shared<CreateStarPacket>();
				break;
			case (int)ePacketNumber::RemoveStar:
				packet = std::make_shared<RemoveStarPacket>();
				break;
			case (int)ePacketNumber::MoveStar:
				packet = std::make_shared<MoveStarPacket>();
				break;
			}
			
			packet->Deserialize(buffer);
			packetQueue->push(packet);			
		}
		else
		{
			break;
		}
	}

	return packetQueue->size() > 0;
}

SOCKET Connection::GetSocketHandle()
{
	return mSocket.GetSocketHandle();
}