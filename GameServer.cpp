#include "GameServer.h"


GameServer::GameServer(HINSTANCE hInstance, int nCmdShow)
    : Window(hInstance, nCmdShow)    
{
    
}

GameServer::~GameServer()
{

}

bool GameServer::Listen()
{
    return true;
}