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
class SortedObjectPool
{
public:
    SortedObjectPool();

    T& operator[](std::size_t i);
    const T& operator[](std::size_t i) const;
    T& at(size_t i);
    const T& at(size_t i) const;

    void add(T& object);
    void clear();
    void remove(size_t i);

    void setMaximumSize(unsigned int size);

    //gets
    unsigned int getSize() const;
    //sets

private:
    unsigned int current_size;
    std::vector<T> vector;
};

//cpp below

template <class T>
SortedObjectPool<T>::SortedObjectPool()
{
    current_size = 0;
}

template <class T>
T& SortedObjectPool<T>::operator[](std::size_t i)
{
    return vector[i];
}

template <class T>
const T& SortedObjectPool<T>::operator[](std::size_t i) const
{
    return vector[i];
}

template <class T>
T& SortedObjectPool<T>::at(size_t i)
{
    return vector.at(i);
}

template <class T>
const T& SortedObjectPool<T>::at(size_t i) const
{
    return vector.at(i);
}

template <class T>
void SortedObjectPool<T>::add(T& object)
{
    if (getSize() < vector.size())
    {
        bool not_found = true;
        unsigned int n = 0;

        while (not_found && n < getSize())
        {
            //search for place to insert
            if (object < vector.at(n))
            {
                //insert here and push everything back
                for (unsigned int m = n; m < getSize() + 1; m++)
                {
                    std::swap(object, vector.at(m));
                }

                not_found = false;
            }
            else
            {
                n++;
            }
        }

        if (not_found) //needs to be placed in last slot
        {
            std::swap(object, vector.at(getSize()));
        }

        current_size++;
    }
}

template <class T>
void SortedObjectPool<T>::clear()
{
    current_size = 0;
}

template <class T>
void SortedObjectPool<T>::remove(size_t i)
{
    if (getSize() > 0)
    {
        for (unsigned int n = i; n < getSize() - 1; n++)
        {
            std::swap(vector.at(n), vector.at(n + 1));
        }

        current_size--;
    }
}

template <class T>
void SortedObjectPool<T>::setMaximumSize(unsigned int size)
{
    vector.resize(size);

    if (getSize() > size)
    {
        current_size = size;
    }
}

//gets
template <class T>
unsigned int SortedObjectPool<T>::getSize() const
{
    return current_size;
}
