#include "CommonLibrary.h"
#include "StarGameServer.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    StarGameServer server(hInstance, nCmdShow);

    if (server.Listen())
    {        
        server.Run();
    }
    else
    {
        MessageBox(NULL, L"Can't Execute Server...", L"ERROR", 0);
    }
}