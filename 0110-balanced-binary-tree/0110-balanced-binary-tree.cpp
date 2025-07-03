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
    int ans = 0;
    int diff(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int x = diff(root->left);
        int y = diff(root->right);
        ans=max(ans,abs(x-y));
        return 1+max(x,y);
    }


    bool isBalanced(TreeNode* root) {
        diff(root);
        if(ans>1) return false;
        return true;
    }
};