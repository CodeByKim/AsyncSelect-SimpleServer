#include "GameServer.h"
#include "Connection.h"
#include "Util.h"
#include "Packet.h"

GameServer::GameServer(HINSTANCE hInstance, int nCmdShow)
    : Window(hInstance, nCmdShow)
	, mConnectionPool(MAX_CCU)
	, mConnections {}
	, mAcceptor(mConnectionPool)
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
	mAcceptor.Run();	

	RegisterUserMessage(FD_ACCEPT, std::bind(&GameServer::AcceptNewConnection, this, std::placeholders::_1));
	RegisterUserMessage(FD_READ, std::bind(&GameServer::Receive, this, std::placeholders::_1));
	
	Window::Run();
}

void GameServer::AcceptNewConnection(SOCKET sock)
{		
	 Connection* connection = mAcceptor.Accept();	 
	 mConnections.insert(std::make_pair(connection->GetSocketHandle(), connection));

	 OnConnect(connection);
}

void GameServer::Receive(SOCKET sock)
{	
	Connection* connection = mConnections[sock];
	int recvSize = connection->Receive();

	if (recvSize > 0)
	{
		std::queue<std::shared_ptr<Packet>> packetQueue;
		connection->GetPacket(&packetQueue);

		while (!packetQueue.empty())
		{
			auto packet = packetQueue.front();
			packetQueue.pop();

			OnReceive(connection, packet.get());
		}
	}
	else
	{
		OnDisconnect(connection);
	}	
}