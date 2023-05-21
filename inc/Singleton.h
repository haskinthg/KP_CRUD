#ifndef USINGLETON_H
#define USINGLETON_H

#include "stable.h"

//#pragma warning(disable : 4355)

template <class T>
class Singleton {
public:
    Singleton(T& rObject)
    {
        Instance = &rObject;
    }
    ~Singleton()
    {
        Instance = 0;
    }
    static T& instance()
    {
        if (!Instance) {
            Instance = new T();
        }
        return (*Instance);
    }

private:
    static T* Instance;
    Singleton(const Singleton& Src);
    Singleton& operator=(const Singleton& Src);
};
template <class T>
T* Singleton<T>::Instance = 0;

#endif // USINGLETON_H
