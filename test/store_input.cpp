#include <iostream>

int main(){
    int num;
    std::cout<< "how many items?";
    std::cin>> num;
    int *arr = new int[num];
    for (int i=0; i < num; ++i){
        std::cout << "enter item" << i << ":";
        std::cin >> arr[i];
    }
    for (int i = 0; i < num; ++i){
        std::cout << arr[i] << std::endl;
    }
    delete[] arr;
}