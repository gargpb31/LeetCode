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

    




    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL && q==NULL) return true;
       if(p==NULL || q==NULL) return false;

       if(p->val!=q->val) return false;

       stack<TreeNode*> s1,s2;

       s1.push(p);
       s2.push(q);

       while(!s1.empty())
       {
        p=s1.top();
        q=s2.top();
        s1.pop();
        s2.pop();

            if(p->val!=q->val) return false;

            if(p->right==NULL && q->right==NULL);
            else if(p->right==NULL || q->right==NULL) return false;
            else
            {
                s1.push(p->right);
                s2.push(q->right);
            }


            if(p->left==NULL && q->left==NULL);
            else if(p->left==NULL || q->left==NULL) return false;
            else
            {
                s1.push(p->left);
                s2.push(q->left);
            }
       }
       return true;
    }
};