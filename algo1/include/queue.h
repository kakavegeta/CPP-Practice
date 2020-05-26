#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include <iostream>

const int DEFAULT_CAPACITY = 100;
template<typename T>
class Queue {

    public:
    Queue(int cap = DEFAULT_CAPACITY)
        :_cap{cap}, _size{0}, _elements{new T[_cap]},
        _head{0}, _tail{-1} { };
    
    ~Queue() {
        delete [] _elements; 
    }

    bool empty() {
        return (_size == 0);
    }

    bool push(const T& t){
        if(_size == _cap) return false;
        ++_tail;
        ++_size;
        // enqueue in a circular way
        if(_tail == _cap) _tail = 0;
        _elements[_tail] = t; 
        return true;
    }


    void pop() {
        if(empty()) return;

        ++_head;
        --_size; 
        if(_head == _cap) _head = 0;
    }

    const T& front() {
        if(empty()) throw QueueEmptyException{};
        return _elements[_head];
    }

    int size() {
        return _size;
    }

    private:
    int _cap;
    int _size;
    int _head;
    int _tail;
    T* _elements;

    class QueueEmptyException {};

    Queue(Queue& q);

    Queue & operator = (const Queue & q);

};

#endif