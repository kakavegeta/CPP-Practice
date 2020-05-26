#include <iostream>
#include "list.h"

int main(void) {
    algo::List<int> list;

    for(int i=0; i<10; i++) {
        list.push_back(i);
    }

    for(int i=0; i<5; i++) {
        std::cout << list.front() << " ";
        list.pop_front();
        std::cout << list.back() << " ";
        list.pop_back();
    }

    std::cout << std:: endl;
}