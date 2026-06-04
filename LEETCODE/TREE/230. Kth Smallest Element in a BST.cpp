class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        while(root) {

            if(root->left == nullptr) {
                if(--k == 0) return root->val;
                root = root->right;
            }
            else {

                TreeNode* pred = root->left;

                while(pred->right && pred->right != root)
                    pred = pred->right;

                if(pred->right == nullptr) {
                    pred->right = root;
                    root = root->left;
                }
                else {
                    pred->right = nullptr;

                    if(--k == 0) return root->val;

                    root = root->right;
                }
            }
        }

        return -1;
    }
};