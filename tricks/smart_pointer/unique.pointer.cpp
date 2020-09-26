/*************************************************************************
	> File Name: unique.pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Sep 2020 05:25:30 PM EDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<memory>
using namespace std;

class Dog {
    public:
    string name;
    void bark() {cout << "dog " << name << " barks"<< endl;}
    Dog():name{"nameless"} {cout << "nameless dog created" << endl;}
    Dog(string s): name{s} {cout << "dog is create: " << name << endl;}
    ~Dog() {cout << "dog is destoryed: " << name <<endl;}
};

void test (){
    Dog *pd = new Dog("Gunner");
    pd->bark();
    // if retrun before delete pd, memory is leaked
    delete pd;
}

void test2() {
    unique_ptr<Dog> pd(new Dog("Gunner"));
    pd->bark(); // no longer need to delete pd

    //Dog* p = pd.release();
}

void test3() {
    unique_ptr<Dog> pd(new Dog("Gunner"));
    pd->bark();
    Dog* p = pd.release();
    if (!pd) {
        cout << "pd is empty" << endl;
    }
}

void test4() {
    unique_ptr<Dog> pd(new Dog("Gunner"));
    pd->bark();
    pd.reset(new Dog("Smokey"));
    // pd.reset() now pd become empty;
    if (!pd) {
        cout << "pd is empty" << endl;
    }   
}

void test5() {
    unique_ptr<Dog> pd(new Dog("Gunner"));
    unique_ptr<Dog> pd2(new Dog("Smokey"));
    pd2->bark();
    pd2 = move(pd);
    pd2->bark();
}

int main() {
    test5();
}

 
