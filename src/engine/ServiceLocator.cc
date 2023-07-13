#include <engine/ServiceLocator.hh>

#include "services/Window.hh"

#define SERVICE_DECLARE(serviceName, serviceInterface) g_serviceLocator->provide<serviceInterface>(new serviceName())

ServiceLocator* ServiceLocator::init() {
    g_serviceLocator = new ServiceLocator();

    SERVICE_DECLARE(WindowService, IWindowService);

    return g_serviceLocator;
}
