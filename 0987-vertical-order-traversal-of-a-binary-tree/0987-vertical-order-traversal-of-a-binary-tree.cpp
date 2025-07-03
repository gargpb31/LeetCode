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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        multiset<pair<pair<int,int>,int>> s;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0},root});
        while(!q.empty())
        {
            auto x = q.front();

            q.pop();

            s.insert({{x.first.second,x.first.first},x.second->val});

            if(x.second->left!=NULL)
            {
                q.push({{x.first.first+1,x.first.second-1},x.second->left});
            }
            if(x.second->right!=NULL)
            {
                q.push({{x.first.first+1,x.first.second+1},x.second->right});
            }
        }
        int g = 0;
        map<int,int> m;
        for(auto it : s)
        {
            if(m.find(it.first.first)==m.end())
            {
                m[it.first.first]=g;
                ans.push_back({});
                g++;
            }
            ans[m[it.first.first]].push_back(it.second);
        }
        return ans;
    }
};