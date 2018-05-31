#pragma once

#include <vector>

/*
Class that stores an object pool. It reuses old objects instead of creating new ones.
*/

template <class T>
class ObjectPool
{
public:
    ObjectPool();

    T& operator[](size_t i);
    const T& operator[](size_t i) const;
    T& at(size_t i);
    const T& at(size_t i) const;

    void add(const T& object);
    void clear();
    void remove(size_t i);

    //gets
    size_t getCurrentCount() const;
    size_t getMaximumCount() const;
    //sets
    void setMaximumCount(size_t size);

private:
    size_t current_count;
    std::vector<T> vector;
};


//cpp below

template <class T>
ObjectPool<T>::ObjectPool()
{
    current_count = 0;
}

template <class T>
T& ObjectPool<T>::operator[](std::size_t i)
{
    return vector[i];
}

template <class T>
const T& ObjectPool<T>::operator[](std::size_t i) const
{
    return vector[i];
}

template <class T>
T& ObjectPool<T>::at(size_t i)
{
    vector.at(i);
}

template <class T>
const T& ObjectPool<T>::at(size_t i) const
{
    vector.at(i);
}

template <class T>
void ObjectPool<T>::add(const T& object)
{
    if (getCurrentCount() < vector.size())
    {
        vector.at(getCurrentCount()) = object;
        current_count++;
    }
}

template <class T>
void ObjectPool<T>::clear()
{
    current_count = 0;
}

template <class T>
void ObjectPool<T>::remove(size_t i)
{
    if (getCurrentCount() > 0)
    {
        std::swap(vector.at(i), vector.at(current_count - 1));
        current_count--;
    }
}

//gets
template <class T>
size_t ObjectPool<T>::getCurrentCount() const
{
    return current_count;
}

template <class T>
size_t ObjectPool<T>::getMaximumCount() const
{
    return vector.capacity();
}

//sets
template <class T>
void ObjectPool<T>::setMaximumCount(size_t count)
{
    vector.resize(size);

    if (getCurrentCount() > count)
    {
        current_count = count;
    }
}
