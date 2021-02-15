#include "Acceptor.h"
#include "Util.h"

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