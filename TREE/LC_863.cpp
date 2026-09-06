/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // converting tree into graph by introducing a map 
    // and we will keep track of which node is visited, for example i go from 5-1 and then again  from 1-5 its not okay because its already covered in 0th level of bfs

    unordered_map<TreeNode*, TreeNode*> parent;
    // for making map i will use inorder traversal of tree
    void inOrder(TreeNode* root){
        if(root == NULL) return;

        if(root->left) parent[root->left] = root;
        inOrder(root->left);
        if(root->right) parent[root->right] = root;
        inOrder(root->right);
    }
    void bfs(TreeNode* target, vector<int> &result, int k){
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        while(!q.empty()){
            int n = q.size();
            if(k == 0) break;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            result.push_back(currNode->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            vector<int> result;

            inOrder(root);

            bfs(target, result, k);
            return result;
    }
};