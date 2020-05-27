#include <iostream>
#include "vector.h"

int main() {
    algo::Vector<int> vec;
    for(int i=0; i<10; ++i) {
        vec.push_back(i);
    }

    for(int i=0; i<vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.clear();

    for(int i=10; i<20; ++i) {
        vec.push_back(i);
    }

    for(int i=0; i<vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}