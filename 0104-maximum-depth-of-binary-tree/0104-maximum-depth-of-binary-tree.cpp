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
    int func(TreeNode* root)
    {
        if(root==NULL) return 0;

        int lef  = func(root->left);
        int rig = func(root->right);

        return max(lef,rig)+1;
    }

    int maxDepth(TreeNode* root) {
        return func(root);
    }
};