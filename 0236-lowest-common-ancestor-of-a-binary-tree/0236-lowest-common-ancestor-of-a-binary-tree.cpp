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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,TreeNode*> m;
        m[root]=root;
       queue<TreeNode*> q1;
       q1.push(root);
       while(!q1.empty())
       {
            TreeNode* root2=q1.front();
            q1.pop();

            if(root2->right!=NULL) {m[root2->right]=root2; q1.push(root2->right); }
            if(root2->left!=NULL) {
                m[root2->left]=root2;
                q1.push(root2->left);  }

       }

       map<TreeNode*,int> m2;
       if(p==root || q==root) return root;
        m2[p]++;
       TreeNode* node = m[p];
       m2[node]++;
       while(node!=root)
       {
            node=m[node];
            m2[node]++;


       }
       m2[q]++;
       if(m2[q]==2) return q;
      node = m[q];
       m2[node]++;
       if(m2[node]==2) return node;

       while(node!=root)
       {
        node=m[node];
        m2[node]++;
        if(m2[node]==2) return node;
       }
       return root;








    }
};