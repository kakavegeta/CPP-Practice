//#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> hours{8,4,2,1};
        vector<int> minutes{32,16,8,4,2,1};
        for (int k=0; k<=num; ++k){
            vector<int> hours_sum = time_sum(hours, k);
            vector<int> minutes_sum = time_sum(minutes, num-k);
            for(auto hour: hours_sum){
                if(hour>11){continue;}
                for(auto minute: minutes_sum){
                    if(minute>59){continue;} 
                    res.push_back(to_string(hour) + ":" + ((minute<10) ? "0"+to_string(minute):to_string(minute)));
                }
            }
        }
        return res;
    };
    
    vector<int> time_sum(const vector<int>& nums, int count){
        vector<int> res;
        helper(nums, count, 0, 0, res);
        return res;
    }
    
    void helper(const vector<int>& nums, int count, int pos, int sum, vector<int>& res){
        if(count==0){
            res.push_back(sum);
            return;
        }
        
        for(int i=pos; i<nums.size();++i){
            helper(nums, count-1, i+1, sum+nums[i], res);
        }
    }
    
};