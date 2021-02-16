#pragma once

#include "CommonLibrary.h"

class Util
{
public:
	void PrintError(const wchar_t* message);
	void PrintLog(const wchar_t* message);
	void PrintLog(const wchar_t* title, const wchar_t* message);

	static Util& GetInstance();
};

