#pragma once

#include "Service.hh"
#include <string>
#include <common.hh>

enum WindowMode {
    WINDOWED,
    BORDERLESS,
    FULLSCREEN
};

struct WindowOpenParams {
    u32 width;
    u32 height;
    std::string title;
    WindowMode mode;
};

struct IWindowService : Service<IWindowService> {
    virtual void open(WindowOpenParams params) = 0;
    virtual void close() = 0;
    virtual void run() = 0;
};
