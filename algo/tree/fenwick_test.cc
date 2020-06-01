#include <iostream>
#include "fenwick.h"

int main() {
    int data[10];
    for(int i = 0; i<10; i++) {
        data[i] = i;
    }


    algo::FenwickTree<int> ft(10);
    for(int i = 0; i<10; ++i) {
        ft.update(i+1, data[i]);
    }

    std::cout << ft.rangeSum(0, 4) << std::endl;
    ft.update(1, 2);
    std::cout << ft.rangeSum(0, 4) << std::endl;
    
    return 0;
}