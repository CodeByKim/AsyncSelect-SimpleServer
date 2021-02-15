#pragma once
#include "CommonLibrary.h"

class GameServer
{
public:
	GameServer(HINSTANCE hInstance, int nCmdShow);
	~GameServer();

	bool Listen();
	void Run();

protected:

private:
	HINSTANCE mhInstance;
};

