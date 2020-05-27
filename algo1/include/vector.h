#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdlib.h>
#include <iostream>
#include <exception>

namespace algo {

template<typename T>
class Vector {

    public:

    explicit Vector(int s = 0)
        : _size{s}, _cap{_size+2}{
            items = new T[_cap];
        }
    
    Vector(const Vector &rhs) 
       :_size{rhs._size}, _cap{rhs._cap}, items{nullptr} {
           items = new T[_cap];
           for(int i=0; i<_size; ++i) {
               items[i] = rhs.items[i];
           }
       }
    
    Vector(Vector && rhs) 
        :_size(rhs._size), _cap{rhs._cap}, items{rhs.items} 
    {
        rhs.items = nullptr;
        rhs._size = 0;
        rhs._cap = 0;   
    }

    Vector & operator= (const Vector& rhs);
    //Vector & oeprator= (Vector&& rhs);
     ~Vector () {delete [] items;}

    T& operator[] (int idx) {
        if(idx < 0 || idx >=_size) {
            throw IndexOutOfBound{};
        }
        return items[idx];
    }

    void resize(int s) {
        if(s > _cap) {
            reserve(s*2);
        }
        _size = s;
    }

    void reserve(int c) {
        if(c < _cap) {
            return;
        }

        T* new_items = new T[c];
        for(int i=0; i<_size; ++i) {
            new_items[i] = items[i];
        }
        std::swap(items, new_items);
        _cap = c;
        delete [] new_items;
    }


    void push_back(const T& t) {
        if(_size == _cap) {
            reserve(_cap*2+1);
        }
        items[_size++] = std::move(t);
    }

    void pop_back() {
        if(empty()) throw VectorEmptyException{};
        --_size;
    }

    const T& back() const {
        if(empty()) throw VectorEmptyException{};
        return items[_size-1];
    }

    int size() {
        return _size;
    }

    bool empty() {
        return (_size==0);
    }

    int capacity() {
        return _cap;
    }
    

    void clear() {
        _size = 0;
        _cap = 2;
        delete [] items;
        items = new T[_cap];
    }

    typedef T *iterator; 
    typedef const T *const_iterator;

    iterator begin() {
        return &items[0];
    }

    const_iterator begin() const {
        return &items[0];
    }

    iterator end() {
        return &items[_size];
    }

    const_iterator end() const {
        return &items[_size];
    }

    static const int SPARE_CAPACITY = 2;

    private:
    int _size;
    int _cap;
    T *items;
    class IndexOutOfBound {};
    class VectorEmptyException {};
    


};




}


#endif