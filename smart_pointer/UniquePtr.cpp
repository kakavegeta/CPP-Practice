/*************************************************************************
	> File Name: UniquePtr.cpp
	> Author: akira
	> Mail: 
	> Created Time: Sat 07 Nov 2020 02:05:17 AM EST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <utility>

using namespace std;

struct MyInt {
    MyInt(int i): i_{i} {}
    ~MyInt() {
        cout << "good bye from " << i_ << endl;
    }
    int i_;
};


int main() {
    cout << endl;
    unique_ptr<MyInt> up1{new MyInt(1998)};

    cout << "up1.get(): " << up1.get() << endl;  
    unique_ptr<MyInt> up2{move(up1)};
    cout << "up1.get(): " << up1.get() << endl;  
    cout << "up2.get(): " << up2.get() << endl;  
    cout << endl;

    {
        unique_ptr<MyInt> local_ptr{new MyInt(2003)};
    }
    cout << endl;

    up2.reset(new MyInt(2011));
    MyInt *myint = up2.release();
    delete myint;
    cout << endl;



}

