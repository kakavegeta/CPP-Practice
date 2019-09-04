#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<vector<int>> q;
        //vector<int> cur{r0, c0};
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<int>> res;
        int len;
        q.push({r0, c0});
        while(!q.empty()){
            len = q.size();
            for(int i=0; i<len; ++i){
                vector<int> cur = q.front();
                q.pop();
                int r = cur[0];
                int c = cur[1];
                if(visited[r][c]) continue;
                res.push_back({r, c});
                visited[r][c] = true;
                if(r-1>=0) q.push({r-1, c});
                if(r+1<R) q.push({r+1, c});
                if(c-1>=0) q.push({r,c-1});
                if(c+1<C) q.push({r,c+1});

            }
        }
        return res;
    }

    vector<vector<int>> allCellsDistOrder2(int R, int C, int r0, int c0) {  
        vector<vector<int>> result(R * C, vector<int>(2, 0));
        
        vector<int> bucket(R + C + 1, 0); 
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                bucket[abs(i - r0) + abs(j - c0) + 1]++; 
            }
        }
        
        for (int i = 1; i < R + C + 1; i++) {
            bucket[i] += bucket[i - 1];
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dis = abs(i - r0) + abs(j - c0);
                result[bucket[dis]][0] = i;
                result[bucket[dis]][1] = j;
                bucket[dis]++;
            }
        }
        
        return result;
    }
};