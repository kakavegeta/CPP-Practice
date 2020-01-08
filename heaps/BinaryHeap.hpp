#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "dsexception.hpp"
#include <vector>

template <typename T>
class BinaryHeap{
    public:
        explicit BinaryHeap(int capacity = 100):
        current_size{0}, array(capacity+1){}

        explicit BinaryHeap(const std::vector<T>& items):
        array(items.size()+10), current_size{items.size()} {
            for(int i = 0; i < items.size(); ++i){
                array[i+1] = items[i];
            }
            build_heap();
        }

        const T& find_min() const{
            if(is_empty()) throw UnderflowException();
            return array[1];
        }


        void insert(const T& item){
            if(current_size == array.size() - 1) array.resize(2*array.size());
            int hole = ++current_size;
            T copy = item;
            array[0] = std::move(copy); // terminate when item is new minimum
            for(; item < array[hole/2]; hole/=2){
                array[hole] = std::move(array[hole/2]);
            }
            array[hole] = std::move(array[0]);
        }


        void insert(T&& item){
            if(current_size == array.size() - 1) array.resize(2*array.size());
            int hole = ++current_size;
            for(; hole > 1 && item < array[hole/2]; hole /= 2){
                array[hole] = std::move(array[hole/2]);
            }
            array[hole] = std::move(item);
        }


        void delete_min(){
            if(is_empty()) throw UnderflowException{};
            array[1] = std::move(array[current_size--]);
            percolate_down(1);
        }

        void delete_min(T& item){
            if(is_empty()) throw UnderflowException{};
            item = std::move(array[1]);
            array[1] = std::move(array[current_size--]);
            percolate_down(1);
        }

        void make_empty(){
            current_size = 0;
        }

        bool is_empty() const{
            return current_size==0;
        }

    private:
        int current_size;
        std::vector<T> array;
        
        void build_heap(){
            for(int i = current_size/2; i > 0; --i){
                percolate_down(i);
            }
        }

        void percolate_down(int hole){
            T temp = std::move(array[hole]);
            int child;
            while(hole*2 <= current_size){
                child = hole * 2;
                if(child != current_size && array[child+1] < array[child]){
                    ++child;
                }
                if(array[child] < temp)
                    array[hole] = std::move(array[child]);
                else
                    break;
                hole = child;
            }
            array[hole] = std::move(temp);
        }
};


#endif