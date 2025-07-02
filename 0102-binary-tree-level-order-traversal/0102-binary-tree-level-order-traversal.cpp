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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        stack<pair<int,TreeNode*>> s;

        s.push({0,root});
        ans.push_back({});
        int g = 0;

        while(!s.empty())
        {
            int v = s.top().first;
            TreeNode* r = s.top().second;
            s.pop();
            ans[v].push_back(r->val);

            if(r->right!=NULL)
            {
                if((v+1)>g)
                {
                    ans.push_back({});
                    g++;
                }
                s.push({v+1,r->right});
            }
            if(r->left!=NULL)
            {
                if((v+1)>g)
                {
                    ans.push_back({});
                    g++;
                }
                s.push({v+1,r->left});
            }

        
        }
        return ans;

    }
};