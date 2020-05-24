#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stk(); 
    for (int i=0; i<10; ++i){
        stk.push(i);
    }

    for (int i=0; i<10; ++i) {
        int t = stk.top();
        std::cout << t << " ";
        stk.pop();
    }
    std::cout << std::endl;
    

    return 0;
}