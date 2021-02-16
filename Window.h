#pragma once

#include "CommonLibrary.h"

class Window
{
public:
	Window(HINSTANCE hInstance, int nCmdShow);
	~Window();

	virtual void Run();
	static HWND GetWindowHandle();

protected:
	static void RegisterUserMessage(int message, std::function<void(SOCKET)> func);
	

private:
	void RegisterWindow(HINSTANCE hInstance);
	void Create(int nCmdShow);
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	
	HINSTANCE mhInstance;
	static HWND mhWnd;
	//static std::function<void(WPARAM, LPARAM)> mUserMessageFunc;
	static std::unordered_map<int, std::function<void(SOCKET)>> mUserMessageFuncs;
};