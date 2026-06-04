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
  



bool dfs(TreeNode* root, TreeNode* target,vector<TreeNode*>& path) {
    path.push_back(root);

    if (root == target)
        return true;

    if (root->left && dfs(root->left, target,path))
        return true;

    if (root->right && dfs(root->right, target,path))
        return true;

    path.pop_back(); 
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          vector<TreeNode*> qpath,ppath;
          dfs(root,p,ppath);
          dfs(root,q,qpath);
          TreeNode* ans;
            for(int i=0,j=0;i<ppath.size() && j<qpath.size();i++,j++){
                if(ppath[i]==qpath[j]){
                    ans=ppath[i];
                }
            }
          return ans;
    }
};