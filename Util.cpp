#include "Util.h"

Util& Util::GetInstance()
{
	static Util instance;
	return instance;
}

void Util::PrintError(const wchar_t* message)
{
	wchar_t str[256];
	wsprintf(str, L"[ERROR] %s : %d\n", message, WSAGetLastError());

	OutputDebugString(str);	
}

void Util::PrintLog(const wchar_t* message)
{	
	wchar_t str[256];
	wsprintf(str, L"[LOG] %s\n", message);

	OutputDebugString(str);
}

void Util::PrintLog(const wchar_t* title, const wchar_t* message)
{
	wchar_t str[256];
	wsprintf(str, L"[LOG] %s : %s\n", title, message);

	OutputDebugString(str);
}