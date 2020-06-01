#ifndef _FENWICK_H
#define _FINWICK_H

namespace algo {

template <typename T>
class FenwickTree {
    public:
    FenwickTree(int n)
        :_size{n+1}, _sum{new T[_size]}{} // one-based indexing 
    
    void update(int pos, T delta) {
        while(pos < _size) {
            _sum[pos] += delta;
            pos += pos & (-pos);
        }
    }

    T sum(int pos) {
        T s = 0;
        while(pos > 0) {
           s += _sum[pos];
           pos -= pos & (-pos); 
        }
        return s;
    }

    T rangeSum(int i, int j) {
        return sum(j+1) - sum(i);
    }

    private:
    int _size;
    T* _sum;

};

}
#endif