#include <vector>
#include <stack>
#include <map>

using namespace std;
#include <map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        bool cousin1{false};
        bool cousin2{false};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            cousin1 = false;
            cousin2 = false;
            for(int i=0; i<s; ++i){
                TreeNode *cur = q.front();
                q.pop();

                if(cur->left!=nullptr && cur->right!=nullptr){
                    if(cur->left->val==x && cur->right->val==y) {
                        return false;
                    }
                    if(cur->right->val==x && cur->left->val==y) {
                        return false;
                    }
                }
                if(cur->val==x){ 
                    cousin1 = true;
                }
                if(cur->val==y){
                    cousin2 = true;
                }

                if(cur->left!=nullptr){
                    q.push(cur->left);
                }
                if(cur->right!=nullptr){
                    q.push(cur->right);
                }
            }
            if(cousin1==true && cousin2==true){
                return true;
            }
        
        }
        return false;
    }
};


bool isCousins(TreeNode* root, int x, int y){
    if(!root){
        return false;
    }

    return ~is_siblings(root, x, y) && get_level(root, x)==get_level(root,y);
};

bool is_siblings(TreeNode* root, int x, int y){
    if(!root) return false;
    if(root->left!=nullptr && root->right!=nullptr){
        if(root->left->val==x && root->right->val==y) {
            return true;
        }

        if(root->right->val==x && root->left->val==y) {
            return true;
        }
    }
    return is_siblings(root->left, x, y) || is_siblings(root->right, x, y);

}

int get_level(TreeNode* root, int x, int level=1) {
    if(!root) {
        return 0;
    }
    if(root->val==x) {
        return level;
    }
    int temp = get_level(root->left, x, level+1);
    if(temp==0) {
        return get_level(root->right, x, level+1);
    } else {
        return temp;
    }

}