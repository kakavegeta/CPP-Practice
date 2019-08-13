#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left=0, right=s.length()-1;
        string vowels {"aeiouAEIOU"};
        while(left < right){
            while(vowels.find(s[left])==string::npos && left<right) ++left;
            while(vowels.find(s[right])==string::npos && left<right) --right;
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
        
    }
};