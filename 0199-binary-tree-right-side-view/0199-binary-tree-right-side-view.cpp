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
        vector<int> ans;
        if(root==NULL) return ans;

        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        map<int,int> m;
        while(!q.empty())
        {
            auto x = q.front();

            m[x.first]=x.second->val;

            q.pop();

            if(x.second->left!=NULL)
            {
                q.push({x.first+1,x.second->left});
            }
            if(x.second->right!=NULL)
            {
                q.push({x.first+1,x.second->right});
            }
        }

        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};