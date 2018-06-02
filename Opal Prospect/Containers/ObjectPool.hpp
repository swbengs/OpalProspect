#pragma once

#include <vector>

/*
MIT License

Copyright (c) 2018 Scott Bengs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
