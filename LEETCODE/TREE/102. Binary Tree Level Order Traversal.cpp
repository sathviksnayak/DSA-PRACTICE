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
vector<vector<int>> ans;
void bfs(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);

   
    while(!que.empty()){
        int n=que.size();
         vector<int> row;
         for(int i=0;i<n;i++){
        TreeNode* cur=que.front();
        que.pop();
       
        row.push_back(cur->val);
        if(cur->left) que.push(cur->left);
        if(cur->right) que.push(cur->right);
         }
         ans.push_back(row);   
    }
 
}

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        bfs(root);
        return ans;
    }
};