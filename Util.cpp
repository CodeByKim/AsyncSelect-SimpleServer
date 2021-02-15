#include "Util.h"

Util& Util::GetInstance()
{
	static Util instance;
	return instance;
}

void Util::PrintError(const wchar_t* error)
{
	wchar_t str[256];
	wsprintf(str, L"[ERROR] %s : %d\n", error, WSAGetLastError());

	OutputDebugString(str);	
}

void Util::PrintLog(const wchar_t* log)
{	
	wchar_t str[256];
	wsprintf(str, L"[LOG] %s\n", log);

	OutputDebugString(str);
}
