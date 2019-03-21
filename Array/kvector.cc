#include "kvector.h"
#include <iostream>

namespace kv{

    KVector::KVector(int capacity): size_(0){
        if (capacity<1){
            std::cout<<"cannot make a vector of the size"<<std::endl;
            exit(EXIT_FAILURE);
        }

        int true_capacity = DetermineCapacity(capacity);

        capacity_ = true_capacity;
        data_ = std::unique_ptr<int[]>(new int[true_capacity]);
    }

    
}