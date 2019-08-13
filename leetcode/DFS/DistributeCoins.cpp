#include <vector>
#include <string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        distribute(root, moves);
        return moves;
        
    }

    int distribute(TreeNode *root, int &moves) {
        if(!root) return 0;
        int left = distribute(root->left, moves);
        int right = distribute(root->right, moves);
        moves += abs(left)+abs(right);
        return root->val + left + right -1;


    }
};