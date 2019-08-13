#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        for(int i=0; i<S.length(); ++i){
            last[S[i]-'a'] = i;
        }
        int j=0, anchor=0;
        vector<int> res{};
        for(int i=0; i<S.length(); ++i){
            j = max(j, last[S[i]-'a']);
            if(i==j){
                res.push_back(i-anchor+1);
                anchor = i+1;
            }
        }
    return res;
    }
};