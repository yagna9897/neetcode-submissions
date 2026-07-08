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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else {
            if (p != nullptr && q == nullptr)
                return false;
            else if (p == nullptr && q != nullptr)
                return false;
        }

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;

        bool bIsSubTree = false;
        if (root && subRoot) {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* dummy = q.front();
                q.pop();

                if (dummy != nullptr) {
                    if (dummy->val == subRoot->val) {
                        bIsSubTree = isSameTree(dummy, subRoot);
                        if (bIsSubTree == true) return bIsSubTree;
                    }
                    q.push(dummy->left);
                    q.push(dummy->right);
                }
            }
        }

        return bIsSubTree;
    }
};
