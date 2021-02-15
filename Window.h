#pragma once

#include "CommonLibrary.h"

class Window
{
public:
	Window(HINSTANCE hInstance, int nCmdShow);
	~Window();

	void Run();

private:
	void RegisterClass(HINSTANCE hInstance);
	void Create(int nCmdShow);
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	
	HINSTANCE mhInstance;
	HWND mhWnd;
};

