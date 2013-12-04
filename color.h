#ifndef COLOR_H
#define COLOR_H

class Color
{
    int red,green,blue;
public:
    Color():red(0) {}
    Color(int a,int b, int c):red(a),green(b),blue(c) {}
    int getRed()
    {
        return red;
    }
    int getGreen()
    {
        return green;
    }
    int getBlue()
    {
        return blue;
    }
    class Object;
};

template <class T>
class SharedPointer
{
    T *ptr;
    int count;
    SharedPointer<T>(const SharedPointer<T> &);
    SharedPointer<T> &operator =(const SharedPointer<T> &);
public:
    SharedPointer ();
    SharedPointer (T *ptr): ptr(ptr),count(1) {}
    ~SharedPointer ()
    {
        --count;
        if (count ==0) delete ptr;
    }
    T &operator *()
    {
        return *ptr;
    }
    T *operator ->()
    {
        return ptr;
    }
   /* explicit const bool ()
    {
        return ptr!=0;
    }*/
};

#endif // COLOR_H
