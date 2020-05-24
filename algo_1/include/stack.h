#ifndef STACK_H
#define STACK_H

#include <exception>
#include <cstdint>
#include <iostream>

const int DEFAULT_CAPACITY = 100;

template<typename T>
class Stack {
    public:
    Stack(int capacity = DEFAULT_CAPACITY)
        :_cap{capacity}, _size{0}, _elements{new T[_cap]} {} 
    
    Stack(const Stack& stk)
        :_cap{stk._cap}, _size{stk._size}, _elements{new T[_cap]} {

        for(int i=0; i<size; ++i) {
            _elements[i] = stk._elements[i];
        }
    }

    ~ Stack() {delete [] _elements;}

    Stack & operator = (const Stack& stk);

    int size() {
        return _size;
    }

    bool empty() {
        return (_size == 0);
    }

    void push(const T& t) {
        if(_size == _cap) throw StackOutofBoundException{}; 
        _elements[_size++] = t;
    }

    void pop() {
        if(empty()) return;
        _size--;
    }

    const T& top() {
        if (empty()) throw StackEmptyException {};
        return _elements[_size-1];
    }

    private:
    int _cap;
    int _size;
    T* _elements;

    class StackEmptyException {};
    class StackOutofBoundException {}; 
};

#endif