
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor){
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;

    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int newColor) {
        if(sr<0 || sc<0 || sc>=image[0].size() || sr>=image.size() || image[sr][sc] != color){
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, color, newColor);
        dfs(image, sr+1, sc, color, newColor);
        dfs(image, sr, sc-1, color, newColor);
        dfs(image, sr, sc+1, color, newColor);
    }
};