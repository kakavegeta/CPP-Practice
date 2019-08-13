#include <vector>
#include <algorithm> 
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i:nums1){
            dict[i]++;
        }
        for(int j:nums2){
            if(dict[j]-- > 0){
                res.push_back(j);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int s1 = nums1.size();
        int s2 = nums2.size();
        int p1 = 0, p2 = 0;
        while(p1<s1 && p2<s2){
            if(nums1[p1]==nums2[p2]){
                res.push_back(nums1[p1]);
                ++p1;
                ++p2;
            } else if(nums1[p1]<nums2[p2]) {
                ++p1;
            } else {
                ++p2;
            }
        }
        return res;
    }
};