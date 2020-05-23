#include <stdio.h>
#include <iostream>

class Point {
public:
    int x, y;
    Point(){
        std::cout << "constructor" << std::endl;
    }
    ~Point(){
        std::cout << "destructor" << std::endl;
    }

};

int main(){
    if(true){Point p;}
    std::cout << "p out of scope" << std::endl;
} 