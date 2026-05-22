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
vector<vector<string>> ans;
int height(TreeNode* root){
    if(!root) return 0;
    int left=1,right=1;
    left+=height(root->left);
    right+=height(root->right);
    return max(left,right);
}

void dfs(TreeNode* root,int height,int pos,int n){
        if(!root) return;

        ans[n][pos]=to_string(root->val);
        int lpos=pos-pow(2,height-n-2);
        int rpos=pos+pow(2,height-n-2);
        dfs(root->left,height,lpos,n+1);
        dfs(root->right,height,rpos,n+1);
}
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root);
        int cols=pow(2,h)-1;
        ans.resize(h,vector<string>(cols));
        int pos=(cols-1)/2;
        dfs(root,h,pos,0);

        return ans;
    }
};