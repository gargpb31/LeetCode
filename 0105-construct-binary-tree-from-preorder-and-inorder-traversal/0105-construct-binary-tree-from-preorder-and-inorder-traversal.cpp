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
    void func(map<int,int> &m,int val,TreeNode* &root)
    {
        int r1 = m[val];
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            root = q.front();
            int r2 = m[root->val];
            q.pop();

            if(r1<r2)
            {
                if(root->left==NULL)
                {
                    root->left = new TreeNode(val);
                
                }
                else
                {
                    q.push(root->left);
                }
            }
            else
            {
                if(root->right==NULL)
                {
                    root->right = new TreeNode(val);
                }
                else
                {
                    q.push(root->right);
                }
            }
        }

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        int n = inorder.size();
        for(int i=0; i<n; i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* node = root;
        int val = m[preorder[0]];
        for(int i=1; i<n; i++)
        {
           
            func(m,preorder[i],root);
            
        }
        return node;

    }
};