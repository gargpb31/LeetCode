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
    
    int ans=-1000;
    int func(TreeNode* root,map<TreeNode*,int> &m)
    {
        if(root==nullptr)
        {
            return 0;
        }

        int leftside=func(root->left,m);
        int rightside=func(root->right,m);

        ans = max(ans,leftside+rightside+root->val);
        if(leftside<0 && rightside<0) {ans=max(ans,root->val); return m[root]=root->val;}
        if(leftside>rightside)
        {
            m[root]=leftside+root->val;
            ans=max(ans,m[root]);
            return leftside+root->val;
        }
        m[root]=rightside+root->val;
        ans=max(ans,m[root]);
        return rightside+root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;

        map<TreeNode*,int> m;
    
        int a = func(root,m);
        return ans;

    }   
};