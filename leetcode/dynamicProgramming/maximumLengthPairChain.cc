#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int res = 0;
        for(int i=0,j=0; j<pairs.size(); j++){
            if (j==0 || pairs[i][1]<pairs[j][0])
            {   ++res;
                i = j;
            }
        }
        return res;
    }

    int findLongestChain2(vector<vector<int>> &pairs){
        sort(pairs.begin(), pairs.end(), cmp2);
        vector<int> dp(1, pairs.size());
        for (int i=0; i<pairs.size();++i){
            for (int j=0; j<i; ++j){
                if (pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[i], dp[j]+1);
                else
                    dp[i] = max(dp[i], dp[j]);
            }
        }
        return dp[pairs.size()-1];
    }

private:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }

    static bool cmp2(vector<int> &a, vector<int> &b) {
        return a[0]<b[0];
    }
};
