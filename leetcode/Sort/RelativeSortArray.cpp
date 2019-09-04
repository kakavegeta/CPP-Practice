#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int anchor=0;
        for(auto num2: arr2){
            for(int i=anchor; i<arr1.size(); ++i){
                if(arr1[i]==num2) swap(arr1[anchor++], arr1[i]);
            }
        }
        if(anchor<arr1.size()-1) sort(arr1.begin()+anchor, arr1.end());
        return arr1;
        
    }
};