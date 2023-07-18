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
    void find(TreeNode* root, TreeNode* p,vector<TreeNode*> &v){
        if(root== NULL){
            return;
        }
        v.push_back(root);
        if(root->val>p->val){
            find(root->left,p,v);
        }
        else if(root->val<p->val){
            find(root->right,p,v);
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        find(root,p,v1);
        find(root,q,v2);
        TreeNode* ans = root;
        int i=0;
        while(i<min(v1.size(),v2.size()) and v1[i] == v2[i]){
            ans = v1[i];
            i++;
        }
        return ans;
    }
};