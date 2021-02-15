#pragma once
#include "CommonLibrary.h"
#include "Window.h"

class GameServer : public Window
{
public:
	GameServer(HINSTANCE hInstance, int nCmdShow);
	~GameServer();

	bool Listen();	

protected:

private:
	
};

