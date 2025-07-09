/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void func(TreeNode* root,map<int,int> &m,int va,vector<int> &v,int k)
    {
        queue<pair<TreeNode*,int>> q;
        q.push({root,va});
        m[root->val]++;
        
        while(!q.empty())
        {
            root=q.front().first;
            va=q.front().second;
            if(va==k) v.push_back(root->val);
            
            q.pop();
            
            if(root->left!=NULL)
            {
                if(m.find(root->left->val)==m.end())
                {
                    m[root->left->val]++;
                    q.push({root->left,va+1});
                }
            }
            if(root->right!=NULL)
            {
                if(m.find(root->right->val)==m.end())
                {
                    m[root->right->val]++;
                    q.push({root->right,va+1});
                }
            }
        }
        
    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         map<TreeNode*,TreeNode*> m;
        
        queue<TreeNode*> q;
        q.push(root);
      
        
        m[root]=root;
        map<int,int> m2;
        while(!q.empty())
        {
            TreeNode* r = q.front();
            q.pop();
           
            
            if(r->left!=NULL)
            {
                q.push(r->left);
                m[r->left]=r;
            }
            if(r->right!=NULL)
            {
                q.push(r->right);
                m[r->right]=r;
            }
        }
        vector<int> ans;
        
        func(target,m2,0,ans,k);
        
        int g = 1;
        while(target!=root)
        {
            target=m[target];
            func(target,m2,g,ans,k);
            g++;
           
            
        }
        return ans;
    }
};