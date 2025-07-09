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
    bool isleaf(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        queue<vector<TreeNode*>> q;
        vector<string> ans;
        if(root==NULL) return ans;
        q.push({root});
        
        while(!q.empty())
        {
            vector<TreeNode*> v = q.front();
            q.pop();
            root=v[v.size()-1];
            

            if(root->left!=NULL)
            {
                v.push_back(root->left);
                
                q.push(v);
                v.pop_back();
            }
            if(root->right!=NULL)
            {
                v.push_back(root->right);
                q.push(v);
            }

            if(isleaf(root))
            {
                string s = "";
                for(auto it : v)
                {
                    s += to_string(it->val);
                    s+=('-');
                    s+=('>');
                }
                s.pop_back();
                s.pop_back();
                ans.push_back(s);
            }


        }
        return ans;

    }
};