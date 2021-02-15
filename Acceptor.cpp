#include "Acceptor.h"
#include "Util.h"
#include "Window.h"

Acceptor::Acceptor()	 
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

void Acceptor::StartAccept()
{	
	WSAAsyncSelect(mListenSocket.GetSocketHandle(),
		Window::GetWindowHandle(), UM_SOCKET, FD_ACCEPT);
}