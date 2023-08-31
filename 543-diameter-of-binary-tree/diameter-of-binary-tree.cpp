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
        if(!root){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int d = height(root->left) + height(root->right);
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        return max(d,max(ld,rd));
    }
};