#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K-1);
        
    }

    int atMostK(vector<int>& A, int K) {
        int left=0, res=0;
        unordered_map <int, int> count;
        for(int right=0; right<A.size(); ++right){
            if(!count[A[right]]++) --K;
            while(K < 0){
                if(!--count[A[left]]) ++K;
                left++;
            }
        res += right-left+1;
        }
        return res;
    }
};