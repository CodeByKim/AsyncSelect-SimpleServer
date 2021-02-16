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
	if (!mSocket.Create(sock, addr))
	{
		Util::GetInstance().PrintError(L"Create Socket Error");
	}

	mSocket.SetNonblocking();
}

void Connection::Release()
{

}

int Connection::Receive(char* buffer)
{
	return mSocket.Receive(buffer);
}

int Connection::Send(char* buffer, int size)
{
	return mSocket.Send(buffer, size);
}

SOCKET Connection::GetSocketHandle()
{
	return mSocket.GetSocketHandle();
}