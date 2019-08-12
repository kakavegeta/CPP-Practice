#include <vector>
#include <queue>
#include <deque>

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
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) {
            return true;
        }
        if(root1==nullptr || root2==nullptr){
            return false;
        }
        if(root1->val != root2->val) {
            return false;
        }
        return isSymmetric(root1->left, root2->right) 
                && isSymmetric(root1->right, root2->left);

    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        deque<TreeNode*> q{};
        q.push_back(root->left);
        q.push_back(root->right);
        TreeNode *r1;
        TreeNode *r2;
        while(!q.empty()){
            size_t s = q.size();
            for(int i=0; i<s/2; ++i) {
                r1 = q.front();
                q.pop_front();
                r2 = q.back();
                q.pop_back();
                if(r1==nullptr && r2==nullptr) continue;
                if(r1==nullptr && r2!=nullptr){
                    return false;
                }
                if(r1!=nullptr && r2==nullptr){
                    return false;
                }
                if(r1->val != r2->val) {
                    return false;
                }
                q.push_front(r1->right);
                q.push_front(r1->left); 
                q.push_back(r2->left);
                q.push_back(r2->right);
            }
        }
        return true;

    }
};
