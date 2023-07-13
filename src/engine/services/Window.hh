#pragma once

#include <engine/services/Window.hh>
#include <engine/ServiceLocator.hh>

#include <GLFW/glfw3.h>
#include <iostream>

class WindowService : public IWindowService {
private:
    GLFWwindow* _window;

public:
    void open(WindowOpenParams params) override;
    void close() override;
    void run() override;
};
