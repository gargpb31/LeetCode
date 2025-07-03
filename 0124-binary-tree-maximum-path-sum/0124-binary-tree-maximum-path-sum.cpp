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
    int ansm = -1001;
    int ans1 = 1001;

    int height(TreeNode* root)
    {
        if(root==NULL) return 0;

        int x = height(root->left);
        int y = height(root->right);
        ansm=max(ansm,root->val);
        ans1=min(ans1,root->val);
        ans=max(ans,x+y+root->val);

        if(x<0 && y<0)
        {
            if(root->val>=0) return root->val;
            if(root->val<0) return 0;
        }
        
        
            int z = root->val+max(x,y);
            return max(0,z);

        

     
    }


    int maxPathSum(TreeNode* root) {
         height(root);
        if(ans==0)
        {
            if(ansm<0) return ansm;
        }
         return ans;

    }
};