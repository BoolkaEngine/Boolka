#include "Window.hh"

void WindowService::open(WindowOpenParams params) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    auto width = params.width;
    auto height = params.height;

    GLFWmonitor* monitor = nullptr;
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    if (params.mode != WindowMode::WINDOWED) {
        width = mode->width;
        height = mode->height;

        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    }

    if (params.mode == WindowMode::FULLSCREEN) {
        monitor = glfwGetPrimaryMonitor();
    }

    _window = glfwCreateWindow(width, height, params.title.c_str(), monitor, nullptr);
    if (!_window) {
        std::cerr << "glfwCreateWindow failed" << std::endl;
        close();
        return;
    }
}

void WindowService::close() {
    glfwTerminate();
}

void WindowService::run() {
    while (!glfwWindowShouldClose(_window)) {
        glfwPollEvents();
    }
}
