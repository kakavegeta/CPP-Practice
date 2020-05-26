#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>;
#include <iostream>;
#include <stdexcept>;
#include "dsexception.h";
using namespace std;

template <typename Object>

class Vector{
    public:
        explicit Vector(int initSize=0):
            theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
            {objects = new Object[theCapacity];}
        
        Vector(const Vector &rhs):
            theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(nullptr)
        {
            objects = new Object[theCapacity];
            for (int k=0; k<theSize; ++k)
                objects[k] = rhs.objects[k];
        }

        Vector & operator= (const Vector & rhs)
        {
            Vector copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        ~Vector() {delete [ ] objects;}

        Vector(Vector && rhs):
            theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(rhs.objects)
            {
                rhs.objects = nullptr;
                rhs.theSize = 0;
                rhs.theCapacity = 0;
            }
        
        Vector & operator= (Vector &&rhs)
        {
            std::swap(theSize, rhs.theSize);
            std::swap(theCapacity, rhs.theCapacity);
            std::swap(objects, rhs.objects);
            return *this;
        }

        bool empty() const {return size( )==0;}
        int size() const {return theSize;}
        int capacity() const {return theCapacity;}

        Object & operator[] (int index)
        {
            if (index<0 || index>=size())
                throw ArrayIndexOutOfBoundsException{};
            return objects[index];
        }

        void resize(int newsize)
        {
            if (newsize > theCapacity)
            {
                reserve(newsize*2);
            }
            theSize = newsize;
        }

        void reserve(int newCapacity)
        {
            if (newCapacity<theSize)
                return;
            Object *newArray = new Object[newCapacity];
            for(int k=0; k<theSize; ++k)
                newArray[k] = std::move(objects[k]);
            theCapacity = newCapacity;
            std::swap(objects, newArray);
            delete [ ] newArray;
        }

        void push_back(const Object &x){
            if(theSize == theCapacity)
                reserve(2*theCapacity+1);
            objects[theSize++] = std::move(x);
        }

        void pop_back(const Object &x){
            if(empty())
                throw UnderflowException{ };
            --theSize;
        }

        const Object & back() const {
            if(empty()):
                throw UnderflowException{ };
            return objects[theSize-1];
        }
        
        typedef Object *iterator;
        typedef const Object *const_iterator;

        iterator begin( ) {return &objects[0];}
        const_iterator begin( ) const {return &objects[0];}
        iterator end( ) {return &objects[size()];} 
        const_iterator end() {return &objects[size()];}

        static const int SPARE_CAPACITY = 2;
        
    private:
        int theSize;
        int theCapacity;
        Object *objects;
};

#endif
