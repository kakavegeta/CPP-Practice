/*************************************************************************
	> File Name: MaxSegmentSumM.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Sep 2020 05:17:00 PM EDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
using namespace std;

int mmss_old(int *arr, int m, int n) {
    int dp[m+1][n+1];
    memset(dp, INT_MIN, sizeof(dp)); 

    for (int i=1; i<=m; ++i){
        for (int j=i; j<=n; ++j) {
            int tmp = INT_MIN;
            for (int t=i-1; t<j; ++t) {
                tmp = max(tmp, dp[i-1][t]+arr[j-1]);
            }
            dp[i][j] = max(dp[i][j-1]+arr[j-1], tmp);
            
        }
    }
    int ms = INT_MIN;
    for (int j=m; j<=n; ++j) ms = max(ms, dp[m][j]); 
    return ms;
}

int mmss(int *arr, int m, int n) {
    int max_sum, i, j;
    int cur[n+1];
    int prev[n+1];
    memset(cur, 0, sizeof(cur));
    memset(prev, 0, sizeof(prev));

    for (int i=1; i<=m; ++i){
        max_sum = INT_MIN;
        for (int j=i; j<=n; ++j) {
            // dp[i][j] = max(dp[i][j-1]+s[j], max(dp[i-1][t]+s[j])), i-1<=t<j;
            cur[j] = max(cur[j-1], prev[j-1]) + arr[j-1];
            prev[j-1] = max_sum;
            max_sum = max(max_sum, cur[j]);
        }
    }
    return max_sum;
    
}

int main(){
    int m, n;
    while (scanf("%d%d", &m, &n)==2) {
        int arr[n];
        memset(arr, 0, sizeof(arr));
        for (int i=0; i<n; ++i) cin >> arr[i];
        cout << mmss(arr, m, n) << endl;
    }
    return 0;
}
