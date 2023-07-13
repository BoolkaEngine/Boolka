#pragma once

#include <functional>
#include <memory>
#include <type_traits>
#include <unordered_map>

#include <common.hh>

class ServiceLocator {
private:
    std::unordered_map<size_t, std::shared_ptr<void>> _instances{};

public:
    static ServiceLocator* init();

    void clear() {
        _instances.clear();
    }

    template <typename T>
    void provide(T* instance) {
        const size_t hash = typeid(T).hash_code();
        if (_instances.find(hash) == _instances.end())
            _instances.emplace(hash, std::shared_ptr<void>(instance));
    }

    template <typename T>
    T* get() {
        const size_t hash = typeid(T).hash_code();

        auto instance = _instances.find(hash);
        if (instance == _instances.end())
            return nullptr;

        return std::static_pointer_cast<T>(instance->second).get();
    }
};

inline ServiceLocator* g_serviceLocator;
