/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        ListNode* ans=new ListNode();
        ListNode* fin = ans;
        while(!s.empty())
        {
            int x = s.top();
            s.pop();
            ans->next=new ListNode(x);
            ans=ans->next;
        }
        return fin->next;


    }
};