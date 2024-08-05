#include <engine/ServiceLocator.hh>
#include <engine/services/Window.hh>

extern "C" API_EXPORT void run() {
    ServiceLocator::shared()->provideDefaults();

    auto windowService = IWindowService::get();

    windowService->open({
        .width = 1280,
        .height = 720,
        .title = "Boolka",
        .mode = WindowMode::WINDOWED,
    });

    windowService->run();
}
