#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        if(root->left==nullptr && root->right==nullptr) {
            return true;
        }
        if(root->left!=nullptr && root->left!=nullptr) {

        }
        
    }

};
