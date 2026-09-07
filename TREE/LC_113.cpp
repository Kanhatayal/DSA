/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> ans;
    void solve(TreeNode* root, int target){
        if(!root) return;
        ans.push_back(root->val);
        target -= root->val;
        if((root->left == NULL && root->right == NULL) && target == 0){  
            result.push_back(ans);
        }
        if(root->left) solve(root->left, target);
        if(root->right) solve(root->right, target);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return result;
    }
};