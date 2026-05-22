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
    int depth(TreeNode* root){
        if(!root) return 0;
        int l=1,r=1;
        l+=depth(root->left);
        r+=depth(root->right);
        if(l==1&&r==1) return 1;
        if(l==1 ) return r;
        else if(r==1) return l;
        return min(l,r);

       
    }
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};