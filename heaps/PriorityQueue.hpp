#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "dsexception.hpp"
#include <vector>

template <typename T>
class BinaryHeap{
    public:
        BinaryHeap() = default;
        explicit BinaryHeap(int capacity = 100):
        current_size{0}, array(capacity+1){}

        explicit BinaryHeap(const vector<T>& items):
        array(itmes.size()+10), current_size{items.size()}{
            for(int i = 0; i < items.size(); ++i){
                array[i+1] = items[i];
            }
            build_heap();
        }

        void delete_min(T& item);
        const T& find_min() const;
        void insert(const T& item);
        void insert(T&& item);
        void delete_min();
        void delete_min(T& item);
        void make_empty();
        bool is_empty();

    private:
        int current_size;
        vector<T> array;
        
        void build_heap();
        void percolate_down(int hole);
}


#endif