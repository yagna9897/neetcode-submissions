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
bool GetPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& pvector)
{
    if (root == nullptr) return false;
    pvector.push_back(root);

    if (root == p)
        return true;

    if (root->val < p->val)
    {
        if (GetPath(root->right, p, pvector))
            return true;

    }
    else if (root->val > p->val)
    {
        if (GetPath(root->left, p, pvector))
            return true;
    }

    pvector.pop_back();
    return false;
}
TreeNode* GetTreeNode(vector<TreeNode*>& s1, vector<TreeNode*>& s2)
{
    for (int j = s2.size() - 1; j >= 0; j--)
    {
        TreeNode* jNode = s2[j];
        for(int i = s1.size() - 1; i >= 0; i--)
        {
            TreeNode* dummy = s1[i];

            if (dummy == jNode)
                return dummy;
        }
    }
    return nullptr;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pvector;
    GetPath(root, p, pvector);
    vector<TreeNode*> qvector;
    GetPath(root, q, qvector);

    if (pvector.size() >= qvector.size())
        return GetTreeNode(pvector, qvector);

    return GetTreeNode(qvector, pvector);
}
};
