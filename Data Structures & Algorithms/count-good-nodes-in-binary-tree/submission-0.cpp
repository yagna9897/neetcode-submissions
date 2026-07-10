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

    int count(TreeNode* root, int maxVal)
    {
        if(root == nullptr)
            return 0;

        int res = 0;
        if(root->val >= maxVal)
        {
            res++;
            maxVal = root->val;
        }

        res = res + count(root->left, maxVal) + count(root->right, maxVal);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return count(root, root->val);
    }
};
