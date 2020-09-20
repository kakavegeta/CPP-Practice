/*************************************************************************
	> File Name: LongestIncSubsequence.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Sep 2020 11:23:25 PM EDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>

#define MAXN 1001
using namespace std;

int N;
int arr[MAXN];
int dp[MAXN];

void LIS() {
    int i, j;
    dp[1] = 1;
    for (i=2; i<=N; ++i) {
        int max = 0;
        for(j=1; j<i; ++j) if (arr[i] > arr[j] && max < dp[j]) max = dp[j]; 
        dp[i] = max+1;
    }
}
int main() {
    int i, max;
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d", &arr[i]);
    max = 0;
    LIS();
    for (int i=1; i<=N; ++i) if (max < dp[i]) max = dp[i];
    printf("%d\n", max);
    return 0;
}
