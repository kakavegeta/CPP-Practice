#include "vector"
#include "stack"
#include "map"

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void helper(TreeNode* root, int val, int &sum){
        if(!root) return;
        val = val*2 + root->val;
        if(!root->left && !root->right) 
            sum+=val;
        if(root->left) 
            helper(root->left, val, sum);
        if(root->right) 
            helper(root->right, val, sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }

};