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
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> res;
       if(root==nullptr){
           return res;
       }
       dfs(root, std::to_string(root->val), res);
       return res;
    }

    void dfs(TreeNode* root, string pre, vector<string> &res) {
        if(root->left == nullptr && root->right == nullptr){
            res.push_back(pre);
            return;
        }
        if (root->left!=nullptr){
            dfs(root->left, pre + "->" + std::to_string(root->left->val) , res);
        }
        if (root->right!=nullptr){
            dfs(root->right, pre + "->" + std::to_string(root->right->val), res);
        }
    }

 
};