#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        for(int i=0, j=people.size()-1; i<j; --j){
            if(people[i]+people[j]<=limit) ++i;
            ++res;
        }
        return res;
    }
};