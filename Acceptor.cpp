#include "Acceptor.h"
#include "Util.h"

Acceptor::Acceptor()
	: mListenSocket(INVALID_SOCKET)
	, mAddr {0,}
{

}

Acceptor::~Acceptor()
{

}

void Acceptor::Initialize()
{
	mListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mListenSocket == INVALID_SOCKET)
	{
		Util::GetInstance().PrintError(L"socket");
		return;
	}

	SetNonblockingSocket(mListenSocket);
}

bool Acceptor::Listen()
{
	mAddr.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER_IP, &mAddr.sin_addr.S_un.S_addr);
	mAddr.sin_port = htons(SERVER_PORT);

	if (bind(mListenSocket, (SOCKADDR*)&mAddr, sizeof(mAddr)) == SOCKET_ERROR)
	{
		Util::GetInstance().PrintError(L"bind");
		return false;
	}

	if (listen(mListenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		Util::GetInstance().PrintError(L"listen");
		return false;
	}

	return true;
}

void Acceptor::SetNonblockingSocket(SOCKET socket)
{
	u_long on = 1;
	ioctlsocket(socket, FIONBIO, &on);
}