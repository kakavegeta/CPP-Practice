#include <vector>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T){
        if(S.empty() && T.empty()) return true;
        if(S.empty() || T.empty()) return false;
        
        for(int i=S.length()-1, j=T.length()-1; ; --i, --j){
            for(int back=0; i>=0 && (S[i]=='#' || back!=0); --i){
                back += S[i]=='#'? 1 : -1;
            }
            for(int back=0; j>=0 && (T[j]=='#' || back!=0); --j){
                back += T[j]=='#'? 1 : -1;
            }
            if(i>=0 && j>=0 && S[i]!=T[j]) return false;
            else if(i<0 || j<0) return i==-1 && j==-1;
            }

        }
};