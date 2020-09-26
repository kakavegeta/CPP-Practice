/*************************************************************************
	> File Name: TestApi.h
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Sep 2020 04:57:20 PM EDT
 ************************************************************************/

#ifndef _TESTAPI_H
#define _TESTAPI_H
#include <memory>

class TestApi {
    public:
    TestApi(int s);
    ~TestApi();
    void TestPrint(int num);

    private:
    class TestImpl;
    std::unique_ptr<TestImpl> test_impl;
};
#endif
