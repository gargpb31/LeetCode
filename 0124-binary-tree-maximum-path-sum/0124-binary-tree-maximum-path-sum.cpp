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

   
    int aa = -1000;
    int ans(TreeNode* root)
    {
            if(root==NULL) return 0;

            int x = ans(root->left);
            int y = ans(root->right);

            if(x<0) x=0;
            if(y<0) y=0;
            
            aa=max(aa,root->val+x+y);
            return max(root->val+x,root->val+y);
    }


    int maxPathSum(TreeNode* root) {
        ans(root);

        return aa;
    }
};