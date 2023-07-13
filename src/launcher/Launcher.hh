#pragma once

#include <common.hh>

int app(int argc, char* argv[]);

#ifdef PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define dlopen(path, _) LoadLibraryA(path)
#define dlsym(handle, symbol) GetProcAddress(handle, symbol)

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    return app(__argc, __argv);
}
#else
#include <dlfcn.h>

int main(int argc, char* argv[]) {
    return app(argc, argv);
}
#endif
