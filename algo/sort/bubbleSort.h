#ifndef BUBBLESORT_H
#define BUBBLESORT_H

namespace algo {
    template<typename T>
    static void bubble_sort(T array[]) {
        int n = array.size();
        bool swapped;
        do {
            swapped = false;
            for (int i=1; i<n; ++i) {
                if (array[i-1] > array[i]) {
                    swapped = true;
                    swap(array[i-1], array[i])
                }
            }
        } while (swapped)
    }

}

#endif