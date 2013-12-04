#include "color.h"


template <class T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &ptr)
{
    ptr=ptr.ptr;
    count=++ptr.count;
}

template <class T>
SharedPointer<T> & SharedPointer<T>:: operator =(const SharedPointer<T> &)
{
    if (this!=&ptr)
    {
        --count;
        if (count == 0)
            delete ptr;
        ptr=ptr.ptr;
        count=++ptr.count;
    }
}

