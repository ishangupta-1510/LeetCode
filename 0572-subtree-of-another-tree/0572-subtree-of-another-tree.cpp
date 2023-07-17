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
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root == NULL or subRoot == NULL){
            return root == subRoot;
        }
        return root->val == subRoot->val and check(root->left,subRoot->left) and check(root->right,subRoot->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        if(root->val == subRoot->val){
            if(check(root,subRoot)){
                return true;
            }
        }
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};