/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 29 Sep 2020 02:58:00 PM EDT
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void ex_gcd(int a, int b, int *x, int *y) {
    if (b==0) {
        *x = 1, *y = 0;
        return;
    } 
    int xx, yy;
    ex_gcd(b, a%b, &xx, &yy);
    *x = yy;
    *y = xx - a/b*yy;
    return;
}


int main() {
    int a, b;
    int x, y;
    cin >> a >> b;
    cout <<"gcd(a, b)= " << gcd(a, b) << endl;
    ex_gcd(a, b, &x, &y);
    printf("%d*%d + %d*%d = %d\n", a, x, b, y, a*x+b*y);
    return 0;
}


