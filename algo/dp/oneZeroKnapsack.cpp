/*************************************************************************
	> File Name: oneZeroKnapsack.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Sep 2020 02:42:25 PM EDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>

using namespace std;

const int MAXN = 1000;
const int MAXW = 1000;

int w[MAXN+1];
int v[MAXN+1];
int N, W;
int d[MAXW+1];

void zero_one_knapsack(int d[], const int i) {
    int j;
    for (j=W; j>=w[i]; --j) {
        d[j] = max(d[j], d[j-w[i]]+v[i]); 
    }
}

int main() {
    cin >> N >> W;
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    for (int i=0; i<N; ++i) {
        cin >> w[i];
    }

    for (int i=0; i<N; ++i) {
    }

    return 0;
}



