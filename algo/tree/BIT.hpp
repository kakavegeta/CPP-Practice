/*************************************************************************
	> File Name: BIT.h
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Oct 2020 02:10:22 PM EDT
 ************************************************************************/

#ifndef _BIT_H
#define _BIT_H

inline int lowbit(int i) return i&(-i);

namespace algo {

template<typename T>
class BIT {
public:
    BIT(int n):sz{n+1}, c{new T[sz]} {};


    void add(int i, T val) {
        while (i<=sz) c[i]+=val, i+=lowbit(i);
    }

    T sum(int i) {
        T sum = 0;
        while (i>0) sum+=arr[i], i-=lowbit(i);
        return sum;
    }

private:
    int sz;
    T* c;

};

}

#endif
