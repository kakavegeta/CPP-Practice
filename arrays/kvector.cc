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

    KVector::~KVector(){}

    int KVector::DetermineCapacity(int capacity) const {
        int true_capacity = kMinCapacity;
        while (capacity>true_capacity/kGrowthFactor){
            true_capacity *= kGrowthFactor;
        }
        return true_capacity;
    }

    int KVector::GetCapacity() const {
        return capacity_;
    }

    int KVector::GetSize() const {
        return size_;
    }

    bool KVector::IsEmpty() const {
        return size_==0;
    }

    void KVector::DebugString() const{
        std::cout << "size: " << size_ << std::endl
                  << "capacity: " << capacity_ << std::endl
                  << "elements: " << std::endl;
        for (int i=0; i<size_; ++i){
            printf("%d: %d", i, data_[i]);
            std::cout<<std::endl;
        }
    }

    void KVector::Resize(int new_size) {
        if (size_<new_size){
            if(size_== capacity_){
                IncreaseSize();
            }
        }else if (size_ > new_size){
            if (size_ < capacity_ / kShrinkFactor){
                DecreaseSize();
            }
        }
    }

    void KVector::IncreaseSize(){
        int old_capacity = capacity_;
        int new_capacity = DetermineCapacity(old_capacity);
        if (old_capacity != new_capacity){
            std::unique_ptr<int[]> new_data(new int[new_capacity]);
            for (i=0;i<size_;++i){
                new_data[i] = data_[i];
            }

            data_ = std::move(new_data);
            capacity_ = new_capacity;

        }
    }

    void KVector::DecreaseSize() {
        int old_capacity = capacity_;
        int new_capacity = old_capacity / 2;
        if (new_capacity < kMinCapacity) {
            new_capacity = kMinCapacity;
        }

        if (new_capacity != old_capacity) {
            std::unique_ptr<int[]> new_data(new int[new_capacity]);
            for (int i=0; i<size_;, ++i) {
                new_data[i] = data[i];
            }

            data_ = std::move(new_data);
            capacity_ = new_capacity;
        }
    }

    void KVector::PushBack(int value){
        Resize(size_+1);
        data_[size_] = value;
        ++size_;
    }

    void KVector::Pop() {
        if (size_==0) {
            std::cout << "nothing to pop." << std::endl;
            exit(EXIT_FAILURE);
        }

        Resize(size_-1);
        int val = data[size_-1];
        --size_;
        return val;
    }

    void KVector::Insert(int index, int val) {
        if (index<0 or index >=size_){
            std::cout << "incorrect index." << std::endl;
            exit(EXIT_FAILURE);
        }

        Resize(size_+1);
        for (int i=size_; i>index; ++i) {
            data_[i] = data_[i-1];
        }
        data_[index] = val;
        ++size_;
    }

    void KVector::Prepend(int val) {
        Insert(0, val);
    }

    void KVector::Delete(int index) {
        if (index<0 or index >=size_){
            std::cout << "incorrect index." << std::endl;
            exit(EXIT_FAILURE);
        }

        Resize(size_-1);
        for (int i=index; i<size_-1; ++i){
            data[i] = data[i+1];
        }
        --size_;
    }

    void KVector::Find(int val) const {
        int index_found = -1;
        for(int i=0; i<size_; ++i) {
            if (data[i]==val) {
                index_found = index;
                break;
            }
        }
        return index_found;
    }

    void KVector::Remove(int val) {

    }
    
    
}