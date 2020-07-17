#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <cassert>

namespace algo {
    template<typename T>
    static void selection_sort(T array[], int start, int end) {
        assert(start <= end);
        int i, j, minidx;

        for (i = start; i<end; ++i) {
            minidx = i;
            for (j = i+1; j<=end; ++j) 
                if (array[j] < array[minidx]) 
                    minidx = j;
            if (i != minidx)
                swap(array[i], array[minidx]);
        }
    }
}

#endif
