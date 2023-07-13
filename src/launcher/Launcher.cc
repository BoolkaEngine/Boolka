#include "Launcher.hh"

int app(int argc, char* argv[]) {
    auto handle = dlopen("libgame" PLATFORM_DLL_EXTENSION, RTLD_LAZY);
    if (!handle)
        return -1;

    auto entry = (AppEntry)dlsym(handle, "run");
    if (!entry)
        return -1;

    entry();

    return 0;
}
