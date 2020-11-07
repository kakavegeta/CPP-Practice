/*************************************************************************
	> File Name: SharedPtr.cpp
	> Author: akira
	> Mail: 
	> Created Time: Sat 07 Nov 2020 02:15:17 AM EST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

struct MyInt {
    MyInt(int i): i_{i} {}
    ~MyInt() {
        cout << "good bye: " << i_ << endl;
    }
    int i_;
};


int main() {

    cout << endl;
    shared_ptr<MyInt> sp(new MyInt(1998));
    cout << "sp.use_count(): " << sp.use_count() << endl;

    {
        shared_ptr<MyInt> local_sp(sp);
        cout << "local_sp.use_count(): " << local_sp.use_count() << endl;
    }

    cout << "sp.use_count(): " << sp.use_count() << endl;

    return 0;
}
