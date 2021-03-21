#include <iostream>
#include <new>
#include "queue.h"
template <typename T>
Queue<T>::Queue() {count=0;}

template <typename T>
void Queue<T>::push(T item)
{
    T* p2;
    p2 = p;
    p = new T[count + 1];
    for (int i = 0; i < count; i++)
        p[i] = p2[i];

    p[count] = item;
    count++;
    if (count > 1)
        delete[] p2;
}
template <typename T>
T Queue<T>::pop()
{
    if (count == 0)
        return 0;
    T item;
    item = p[0];
    T *p2 = new T[count - 1];
    count--;
    for (int i = 0; i < count; i++)
        p2[i] = p[i + 1];
    if (count > 0)
        delete[] p;
    p = p2;
    return item;
}
template <typename T>
Queue<T>::~Queue()
{
    delete[] p;
}
template <typename T>
T Queue<T>::front()
{
    if (count > 0)
        return p[0];
    else
        return 0;
}
template <typename T>
T Queue<T>::back(){
    if (count > 0)
        return p[count-1];
    else
        return 0;
}
template <typename T>
bool Queue<T>::empty()
{
    return count == 0;
}
template <typename T>
int Queue<T>::size(){return count;}

