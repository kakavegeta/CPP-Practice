#include <stdio.h>
#include <stdlib.h>

void exch (int i, int j, int arr[]){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t; 
}

void printSol(int arr[], int length){
    for (int i=0; i<length; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

bool canBacktrack(int k, int arr[]){
    for (int i=0; i<k; i++){
        if (abs(arr[i]-arr[k]) == (k-i)) return true;
    }
    return false;
}

void enumerate(int k, int arr[], int length){
    if (k==length){
        printSol(arr, length);
    }
    for (int i=0; i<k; i++){
        exch(k, i, arr);
        if (!canBacktrack(k, arr)){ 
           enumerate(k+1, arr, length);
        }
        exch(i, k, arr);
    }
}

int main(){
    int arr[] = {0, 1, 2, 3, 4};
    int length = 5;
    printSol(arr, length);
    enumerate(0, arr, length);
}
