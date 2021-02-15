#include "Socket.h"
#include "Util.h"

Socket::Socket()
	: mSocket(INVALID_SOCKET)
	, mAddr {0, }
{	
}

Socket::~Socket()
{

}

bool Socket::Create()
{
	mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mSocket == INVALID_SOCKET)
	{
		Util::GetInstance().PrintError(L"socket");
		return false;
	}

	return true;
}

bool Socket::Bind(const char* ip, unsigned short port)
{
	mAddr.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &mAddr.sin_addr.S_un.S_addr);
	mAddr.sin_port = htons(port);

	if (bind(mSocket, (SOCKADDR*)&mAddr, sizeof(mAddr)) == SOCKET_ERROR)
	{		
		return false;
	}

	return true;
}

bool Socket::Listen()
{
	if (listen(mSocket, SOMAXCONN) == SOCKET_ERROR)
	{		
		return false;
	}

	return true;
}

void Socket::SetNonblocking()
{
	u_long on = 1;
	ioctlsocket(mSocket, FIONBIO, &on);
}

SOCKET Socket::GetSocketHandle()
{
	return mSocket;
}