#include <engine/ServiceLocator.hh>

#include "services/Window.hh"

ServiceLocator* ServiceLocator::shared() {
    static auto inst = new ServiceLocator();
    return inst;
}

void ServiceLocator::provideDefaults() {
    provide<IWindowService>(new WindowService());
}
