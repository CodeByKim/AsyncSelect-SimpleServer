#include "Acceptor.h"
#include "Util.h"
#include "Window.h"
#include "ConnectionPool.h"
#include "Connection.h"

Acceptor::Acceptor(ConnectionPool& pool)
	: mPool(pool)
{	
	if (!mListenSocket.Create())
	{
		Util::GetInstance().PrintError(L"Create Acceptor Socket");
		return;
	}

	mListenSocket.SetNonblocking();
}

Acceptor::~Acceptor()
{

}

bool Acceptor::Listen()
{
	if (!mListenSocket.Bind(SERVER_IP, SERVER_PORT))
	{
		Util::GetInstance().PrintError(L"bind");
		return false;
	}

	if (!mListenSocket.Listen())
	{
		Util::GetInstance().PrintError(L"listen");
		return false;
	}

	return true;
}

void Acceptor::Run()
{	
	WSAAsyncSelect(mListenSocket.GetSocketHandle(),
		Window::GetWindowHandle(), UM_SOCKET, FD_ACCEPT);
}

Connection* Acceptor::Accept()
{
	SOCKADDR_IN addr = { 0, };
	int addrSize = sizeof(addr);
	SOCKET clientSocket = accept(mListenSocket.GetSocketHandle(), 
		(SOCKADDR*)&addr, &addrSize);
	
	Connection* connection = mPool.Pop();
	connection->Initialize(clientSocket, addr);

	WSAAsyncSelect(clientSocket, Window::GetWindowHandle(), 
		UM_SOCKET, FD_READ | FD_WRITE | FD_CLOSE);

	return connection;
}