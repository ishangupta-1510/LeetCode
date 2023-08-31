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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1){
            return false;
        }
        bool lbalance = isBalanced(root->left);
        bool rbalance = isBalanced(root->right);
        return lbalance and rbalance;
    }
};