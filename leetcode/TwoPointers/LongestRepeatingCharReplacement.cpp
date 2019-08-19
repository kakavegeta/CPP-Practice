#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26];
        int start=0;
        int max_count=0;
        for(int end=0; end<s.length(); ++end){
            max_count = max(max_count, ++count[s[end]-'A']);
            if(max_count+k < end-start) --count[s[start++]-'A'];
        }
        return s.length();
    }
};