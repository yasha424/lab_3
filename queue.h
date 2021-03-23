#include <iostream>

template <typename T>
class Queue{
private:
  T* arr;
  int capacity;
  int current;
  int popped;

public:
  Queue();
  void push(T item);
  T pop();
  T front();
  T back();
  bool empty();
  int size();
  int curr(); // надо будет удалить
};

template <typename T>
Queue<T>::Queue(){
  capacity = 10;
  arr = new T[10];
  current = 0;
  popped = 0;
}

template <typename T>
void Queue<T>::push(T item){
  if (capacity == current) {
    T *arr2 = new T[capacity*2];
    capacity *= 2;
    for (size_t i = 0; i < capacity/2; i++) {
      arr2[i] = arr[i];
    }
    delete[] arr;
    arr = arr2;
    delete[] arr2;
    std::cout << "was doubled" << std::endl;
  }
  arr[current] = item;
  current++;

}

template <typename T>
T Queue<T>::front(){
  if (current - popped == 0) {
    std::cout << "there is no FRONT!" << std::endl;
    return -1;
  }
  else{
    return arr[current-1];
  }
}

template <typename T>
T Queue<T>::back(){
  if (current - popped== 0) {
    std::cout << "there is no BACK!" << std::endl;
    return -1;
  }
  else{
    return arr[popped];
  }
}

template <typename T>
T Queue<T>::pop(){
  if (current == 0) {
    std::cout << "there is nothing to POP!!!" << std::endl;
  }
  else{
    popped++;
    return arr[popped-1];
  }
}

template <typename T>
bool Queue<T>::empty(){
  if (current-popped != 0) {
    return false;
  }
  else return true;
}

template <typename T>
int Queue<T>::curr(){
  return current;
}

template <typename T>
int Queue<T>::size(){
  return current - popped;
}
