#ifndef SORT_H
#define SORT_H

#include <vector>
#include <functional>

template <typename Comparable>
void quickSort(std::vector<Comparable> &arr){
    quickSort(arr, 0, arr.size()-1);
}


template <typename Comparable>
void quickSort(std::vector<Comparable> &arr, int left, int right) {

    if(left-right>=10){
        const Comparable &p = median3(arr, left, right);
        int i = left+1;
        int j = right-2;
        for(; ;){
            while(arr[i]<p) {++i};
            while(arr[j]>p) {--j};
            if(i<j){std::swap(arr[i], arr[j])}
            else{break;}
        }
        std::swap(a[i], a[right-1]);
        quickSort(arr, left, i-1);
        quickSort(arr, i+1, right);
    }else {
        insertionSort(arr, left, right)
    }




}

template <typename Comparable>
const Comparable &median3(std::vector<Comparable> &arr, int left, int right) {
    int center = (left+right)/2;
    if(arr[center] < arr[left]){
        std::swap(arr[center], arr[left]);
    }
    if(arr[left] < arr[right]) {
        std::swap(arr[left], arr[right]);
    }
    if(arr[center] < arr[right]) {
        std::swap(arr[center], arr[right]);
    }
    std::swap(arr[center], arr[right-1]);
    return arr[right-1];
}

template <typename Comparable>
void insertionSort(std::vector<Comparable> &arr, int low, int high) {
    for(int i=low+1; i<high; ++i){
        Comparable tmp = std::move(arr[i]);
        int j = i;
        while(j>low && tmp < arr[j-1]){
            arr[j] = std::move(arr[j-1])
            --j;
        }
        arr[j] = std::move(tmp);
    }
}

#endif
