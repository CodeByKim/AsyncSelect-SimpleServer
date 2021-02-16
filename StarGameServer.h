#pragma once
#include "GameServer.h"

class Packet;

class StarGameServer : public GameServer
{
public:
	StarGameServer(HINSTANCE hInstance, int nCmdShow);
	~StarGameServer();

protected:
	void OnConnect(Connection* connection) override;
	void OnDisconnect(Connection* connection) override;
	void OnReceive(Connection* connection, Packet* packet) override;

private:
	std::vector<Connection*> mConnections;

	int mID;
};