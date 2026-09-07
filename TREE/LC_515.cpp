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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        // ans.push_back(root->val);
        while(!q.empty()){
            int n = q.size();
            int maxValOfCurrLevel = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* currNode = q.front();
                q.pop();
                maxValOfCurrLevel = max(maxValOfCurrLevel, currNode->val);
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            ans.push_back(maxValOfCurrLevel);
        }
        return ans;
    }
};