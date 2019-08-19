#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0]+nums[1]+nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        for(int first=0; first<nums.size()-2; ++first){
            int second=first+1, third=nums.size()-1;
            while(second<third){
                int sum = nums[first]+nums[second]+nums[third];
                if(sum<target) ++second;
                else --third;
                if(abs(sum-target)<abs(res-target)) res = sum;
            }

        }
        return res;
        
    }
};