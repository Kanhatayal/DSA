class Solution {
public:
    int maxSum = INT_MIN;
    int maxGain(TreeNode* root){
        if(root == NULL) return 0;

        int leftGain = max(maxGain(root->left), 0);
        int rightGain= max(maxGain(root->right), 0);

        int currMaxGain = root->val + leftGain + rightGain;
        maxSum  = max(currMaxGain, maxSum);
        return root->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum; 
    }
};