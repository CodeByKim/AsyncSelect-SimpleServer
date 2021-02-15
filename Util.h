#pragma once

#include "CommonLibrary.h"

class Util
{
public:
	void PrintError(const wchar_t* error);
	void PrintLog(const wchar_t* log);

	static Util& GetInstance();
};

