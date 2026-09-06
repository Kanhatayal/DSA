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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        deque <TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            int n = dq.size();
            ans.push_back(dq.back()->val);
            for(int i = 0; i < n; i++){
                TreeNode* currNode = dq.front();
                dq.pop_front();
                if(currNode->left) dq.push_back(currNode->left);
                if(currNode->right) dq.push_back(currNode->right);
            }
        }
        return ans;
    }
};