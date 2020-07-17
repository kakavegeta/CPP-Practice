#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

namespace algo {
    template<typename T>
    static void insertion_sort(T array[], int n) {
        int val;
        int hole, i;
        for (i=1; i<n; ++i) {
            val = array[i];
            hole = i-1;
            while (hole>=0 && array[hole]>val) {
                array[hole+1] = array[hole];
                hole--;
            }
            array[hole+1] = val;
        }
    }
}


#endif