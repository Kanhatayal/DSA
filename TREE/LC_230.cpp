class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root){
        if(root == NULL) return;

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        // go for inorder traversal on tree and store value in a vector and return k-1th value in that 
        solve(root);
        return ans[k-1];
    }
};