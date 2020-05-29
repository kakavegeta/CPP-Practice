#include "queue.h"
#include <iostream>

int main() {
    Queue<int> q(10);
    for(int i = 0; i<10; ++i) {
        q.push(i);
    }

    std::cout << q.size() << std::endl;
    for(int i=0; i<5; ++i) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    std::cout << q.size() << std::endl;

    for(int i=10; i<20; ++i) {
        q.push(i);
    }

    for(int i=0; i<10; ++i) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;




}