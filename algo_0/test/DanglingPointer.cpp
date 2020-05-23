#include <stdio.h>
#include <iostream>

int main(){
    int *p;
    if (true){
        int x=5;
        p = &x;
    }
    std::cout<< *p <<std::endl;
}