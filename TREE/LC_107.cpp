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
    int getDepth(TreeNode* root){
        if(root == NULL) return 0;

        return  1 + max(getDepth(root->left), getDepth(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        // calculating depth beforehand so that we can allocated space and store ans from the end. 
        int depth = getDepth(root);
        vector<vector<int>> ans(depth);

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> currLevel;
            for(int i = 0; i < n; i++){
                TreeNode* currNode = q.front();
                q.pop();

                currLevel.push_back(currNode->val);
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            ans[depth-1 - level] = currLevel;
            level++;
        }
        return ans;
    }
};