#pragma once

#include <vector>

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
