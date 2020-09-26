/*************************************************************************
	> File Name: TestApi.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Sep 2020 05:00:18 PM EDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include "test_api.h"

class TestApi::TestImpl {
    public:
    void TestPrint(int num);
    TestImpl(int s): start_{s}{}
    TestImpl() = default;
    ~TestImpl() = default;

    private:
    int start_;
};

void TestApi::TestImpl::TestPrint(int num) {
    for (int i=start_; i<num; ++i) {
        std::cout << i << std::endl;
    }
}

TestApi::TestApi(int s) {
    test_impl.reset(new TestImpl(s));
}

void TestApi::TestPrint(int num) {
    test_impl->TestPrint(num);
}

TestApi::~TestApi() = default;
