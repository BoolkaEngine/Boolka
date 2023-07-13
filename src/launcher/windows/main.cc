#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <common.hh>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    HMODULE handle = ::LoadLibrary(L"game.dll");
    if (!handle)
        return -1;

    AppEntry entry = (AppEntry)::GetProcAddress(handle, "run");
    if (!entry)
        return -1;

    entry();

    return 0;
}
