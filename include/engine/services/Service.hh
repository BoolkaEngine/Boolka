#include <engine/ServiceLocator.hh>

template <class T>
struct Service {
    static inline T* get() {
        return ServiceLocator::shared()->get<T>();
    }

    virtual ~Service() {}
};
