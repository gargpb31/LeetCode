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
    


    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL) return 0;
        int ans = 0;
        q.push(root);

        while(!q.empty())
        {
            root=q.front();
            ans++;
            q.pop();

            if(root->left!=NULL)
            {
                q.push(root->left);
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
            }
        }

        return ans;

    }
};