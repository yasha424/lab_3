#include <iostream>
#include <new>
template <typename T>
class Queue
{
private:
    T* p;
    int count;

public:
    Queue();
    void push(T item);
    T pop();
    ~Queue();
    T front();
    T back();
    bool empty();
    int size();
};