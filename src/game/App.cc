#include <engine/ServiceLocator.hh>
#include <engine/services/Window.hh>

extern "C" API_EXPORT void run() {
    g_serviceLocator = ServiceLocator::init();

    auto windowService = g_serviceLocator->get<IWindowService>();
    if (!windowService)
        return;

    windowService->open({
        .width = 1280,
        .height = 720,
        .title = "Boolka",
        .mode = WindowMode::WINDOWED,
    });

    windowService->run();
}
