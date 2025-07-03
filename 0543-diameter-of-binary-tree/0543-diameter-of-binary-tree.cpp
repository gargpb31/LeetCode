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

    int height(TreeNode* root)
    {
        if(root==NULL) return 0;

        int x = height(root->left);
        int y = height(root->right);

        ans=max(ans,x+y);

        return 1+max(x,y);
    }




    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};