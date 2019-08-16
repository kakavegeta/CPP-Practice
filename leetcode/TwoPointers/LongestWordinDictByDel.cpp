#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res{""};
        for(auto word: d){
            if(is_subsequence(s, word)){
                if(word.length()>res.length()) res = word;
                else if(word.length()==res.length() && word<res) res = word;
            }
        }
        return res;
        
    }

    bool is_subsequence(string x, string y){
        int i=0;
        for(auto c: x){
            if(i<y.length() && c==y.at(i)) ++i;
        }
        if(i==y.length()) return true;
        else return false;
    }
};