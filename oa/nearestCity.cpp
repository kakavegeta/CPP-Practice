/*************************************************************************
	> File Name: nearestCity.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Oct 2020 05:27:36 PM EDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int distance(int x, int y, int nx, int ny) {}

vector<string> nearestCity(int n, vector<string>& cities, vector<int>& xs, vector<int>& ys, int m, vector<string>& queries) {
    map<int, vector<string>> xmap;
    map<int, vector<string>> ymap;
    unordered_map<string, vector<int>> cityMap;
    unordered_map<string, string> ctc;

    for (int i=0; i<n; ++i) {
        xmap[xs[i]].push_back(cities[i]);
        ymap[ys[i]].push_back(cities[i]);
        cityMap[cities[i]] = {xs[i], ys[i]};
    }

     

    for (int i=0; i<n; ++i) {
        int x = cityMap[cities[i]][0], y = cityMap[cities[i]][1];
        if (xmap.count(x) || ymap.count(y)) {
            int dist = INT_MAX;
            string city = "";
            for (auto c: xmap[x]) {
                int nx = cityMap[c][0];
                int ny = cityMap[c][1];
                if (dist > distance(x, y, nx, ny)) {
                    dist = distance(x, y, nx, ny);   
                    city = c;
                }
            }
            for (auto c: ymap[y]) {
                int nx = cityMap[c][0];
                int ny = cityMap[c][1];
                if (dist > distance(x, y, nx, ny)) {
                    dist = distance(x, y, nx, ny);   
                    city = c;
                }    
            }
            ctc[cities[i]] = city;
        } 
    }

    vector<string> ans;
    for (auto q: queries) {
        ans.push_back(ctc[q]);
    }
    return ans;
}





int main() {
    
}
