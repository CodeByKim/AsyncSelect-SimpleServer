#include "Window.h"
#include "Util.h"

HWND Window::mhWnd;
std::unordered_map<int, std::function<void(SOCKET)>> Window::mUserMessageFuncs;

Window::Window(HINSTANCE hInstance, int nCmdShow)
    : mhInstance(hInstance)
{
    RegisterWindow(hInstance);

    Create(nCmdShow);

    WSADATA data;
    if (WSAStartup(MAKEWORD(2, 2), &data) != 0)
    {
        Util::GetInstance().PrintError(L"WSAStartup");
    }
}

Window::~Window()
{

}

void Window::RegisterWindow(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = WINDOWCLASS_NAME;
    wcex.hIconSm = NULL;

    RegisterClassExW(&wcex);
}

void Window::Create(int nCmdShow)
{    
    mhWnd = CreateWindowW(WINDOWCLASS_NAME, WINDOWCLASS_NAME, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, mhInstance, nullptr);

    ShowWindow(mhWnd, nCmdShow);
    UpdateWindow(mhWnd);
}

void Window::Run()
{
    MSG msg;    
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case UM_SOCKET:
    {
        int msg = WSAGETSELECTEVENT(lParam);
        if (mUserMessageFuncs.find(msg) != mUserMessageFuncs.end())
        {
            mUserMessageFuncs[msg](wParam);
        }        
    }   
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

HWND Window::GetWindowHandle()
{
    return Window::mhWnd;
}

void Window::RegisterUserMessage(int message, std::function<void(SOCKET)> func)
{
    mUserMessageFuncs.insert(std::make_pair(message, func));
}