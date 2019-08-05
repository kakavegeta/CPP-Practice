#include "vector"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution{
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->right = left;
        root->left = right;
        if(root->left!=nullptr) invertTree(root->right);
        if(root->right!=nullptr) invertTree(root->left);
        return root;
    }


};