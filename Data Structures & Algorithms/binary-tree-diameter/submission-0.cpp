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
   private:
    int maxdia;

   public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        int h = 1 + max(lh, rh);
        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int d1 = height(root->left) + height(root->right);
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);
        return max(d1, max(d2, d3));
    }
};
