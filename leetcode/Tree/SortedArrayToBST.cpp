
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
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        if(nums.empty()) return nullptr;
        return helper(nums, 0, nums.size()-1);
        
    }

    TreeNode* helper(vector<int> &nums, int low, int high){
        if(low>high){
            return nullptr;
        }
        int mid = (low+high)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, low, mid-1);
        root->right = helper(nums, mid+1, high);
        return root;
    }
};