/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while(!q.empty()){
            double sum = 0;
            int s = q.size();
            for(int i=0;i<s;++i){
                TreeNode* t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                sum += t->val;
            }
            res.push_back(sum/s);
        }
        return res;
    }
};