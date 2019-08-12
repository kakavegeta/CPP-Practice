#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
 
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left)-height(root->right))<=1;
        
    }

    int height(TreeNode* root) {
        if(!root) return -1;
        return max(height(root->left), height(root->right))+1;
    }
};

class Solution2 {
public:
    bool isBalanced(TreeNode* root)
    {
        bool flag = true;
        height_check(root, flag);
        return flag;
    }

    int height_check(TreeNode *root, bool& flag)
    {
        // change flag when tree is not balanced
        if (!root) return 0;
        int lh = height_check(root->left, flag);
        int rh = height_check(root->right, flag);
        int height = max(lh, rh) + 1;
        if ( abs(lh-rh)>1 ) flag=false;
        return height;
    }
};