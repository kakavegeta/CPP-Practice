/*************************************************************************
	> File Name: cylicReference.cpp
	> Author: akira
	> Mail: 
	> Created Time: Sat 07 Nov 2020 02:28:04 AM EST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
class Deleter {
public:
    void operator()(T *ptr) {
        ++Deleter::count;
        delete ptr;
    }

    void getInfo() {
        string typeId{typeid(T).name()};
        size_t sz = Deleter::count * sizeof(T);
        cout << "Deleted " << Deleter::count <<" objects of type " << typeId << endl;
        cout << "Freed size in bytes: " << sz << endl;
        cout << endl;
    }

private:
    static int count;
};

template <typename T>
int Deleter<T>::count = 0;
typedef Deleter<int> IntDeleter;


int main() {
    cout << endl;

    {
        shared_ptr<int> sp1(new int, IntDeleter());
        shared_ptr<int> sp2(new int, IntDeleter());
        auto intDeleter = get_deleter<IntDeleter>(sp1);
        intDeleter->getInfo();
        sp2.reset();
        intDeleter->getInfo();
    }


}

