#include "vector"
#include "queue"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }

    TreeNode* invertTree2(TreeNode* root){
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;++i){
                TreeNode* t = q.front();
                q.pop();
                TreeNode *tmp;
                tmp = t->right;
                t->right = t->left;
                t->left = tmp;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        } 
        return root;
    }
};

