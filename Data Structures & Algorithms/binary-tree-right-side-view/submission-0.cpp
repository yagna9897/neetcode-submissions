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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize = q.size();
            int res = -101;
            while(levelsize--)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(res == -101)
                    res = node->val;
                if(node->right != nullptr)
                    q.push(node->right);
                if(node->left != nullptr)
                    q.push(node->left);
            }
            if(res >= -100 && res <= 100)
                result.push_back( res);
        }
        return result;
    }
};
