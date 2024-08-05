#pragma once

#include <functional>
#include <memory>
#include <type_traits>
#include <unordered_map>

#include <common.hh>

class ServiceLocator {
private:
    std::unordered_map<size_t, std::shared_ptr<void>> _instances{};

    template <class T>
    static auto _hash() {
        return typeid(T).hash_code();
    }

public:
    static ServiceLocator* shared();

    void provideDefaults();

    template <class T>
    void provide(T* instance) {
        const auto hash = _hash<T>();
        if (_instances.find(hash) == _instances.end())
            _instances.emplace(hash, std::shared_ptr<void>(instance));
    }

    // TODO: throw if null
    template <typename T>
    T* get() {
        const auto hash = _hash<T>();

        auto instance = _instances.find(hash);
        if (instance == _instances.end())
            return nullptr;

        return std::static_pointer_cast<T>(instance->second).get();
    }
};
