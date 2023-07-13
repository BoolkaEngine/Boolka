#pragma once

#include <string>

enum WindowMode {
    WINDOWED,
    BORDERLESS,
    FULLSCREEN
};

struct WindowOpenParams {
    uint32_t width;
    uint32_t height;
    std::string title;
    WindowMode mode;
};

class IWindowService {
public:
    virtual void open(WindowOpenParams params) = 0;
    virtual void close() = 0;
    virtual void run() = 0;
};
