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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});

        while(!q.empty())
        {
            root=q.front().second;
            int lev = q.front().first;
            q.pop();

            if(ans.size()==lev)
            {
                ans.push_back({});
            }
            ans[lev].push_back(root->val);
            if(root->left!=NULL)
            {
                q.push({lev+1,root->left});
            }
            if(root->right!=NULL)
            {
                q.push({lev+1,root->right});
            }
            
        }

        for(int i=0; i<ans.size(); i++)
        {
            if(i%2!=0)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};