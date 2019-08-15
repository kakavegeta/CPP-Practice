#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(nums[slow]!=nums[fast]){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        return nums[slow];
    }
};