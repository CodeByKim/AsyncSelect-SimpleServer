#include "Connection.h"
#include "Util.h"

Connection::Connection()
{	
	//Initialize();
}

Connection::~Connection()
{	
	Release();
}

void Connection::Initialize(SOCKET sock, SOCKADDR_IN addr)
{
	if (mSocket.Create(sock, addr))
	{
		Util::GetInstance().PrintError(L"Create Socket Error");
	}
}

void Connection::Release()
{

}