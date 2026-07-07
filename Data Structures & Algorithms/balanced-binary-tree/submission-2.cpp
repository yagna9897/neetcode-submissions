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

    int height(TreeNode* root, bool& iBbool)
    {
        if(root == nullptr) return 0;
        
        int lh = height(root->left, iBbool);
        int rh = height(root->right, iBbool);
        if(abs(lh -rh) > 1) 
            iBbool = false;
        
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        bool bIsbalanced = true;
        int h = height(root, bIsbalanced);
        return bIsbalanced;
    }
};
