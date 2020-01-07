#include "dsexception.hpp"
#include "BinaryHeap.hpp"

#include <iostream>
#include <string>
#include <sstream>

int main(){
    int minItem = 100;
    int maxItem = 999;
    BinaryHeap<int> bh;
    std::string str = "hello";
    int i = 37;
    std::string x;
    std::cout << "test begins..." << std::endl;

    for(i = 37; i != 0; i = (i+37)%maxItem){
        //std::cout << "hello" << i;
        std::cout << i << std::endl;
    }
}