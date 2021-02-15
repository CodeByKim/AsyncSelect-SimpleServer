#pragma once
#include "GameServer.h"

class StarGameServer : public GameServer
{
public:
	StarGameServer(HINSTANCE hInstance, int nCmdShow);
	~StarGameServer();

protected:
	void OnConnect(Connection* connection) override;
	void OnDisconnect(Connection* connection) override;
	void OnReceive(Connection* connection) override;

private:
	std::vector<Connection*> mConnections;
};

