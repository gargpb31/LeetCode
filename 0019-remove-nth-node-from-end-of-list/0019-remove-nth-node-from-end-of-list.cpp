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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int ct = 0;
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }

        int tr = ct-n;
        if(tr==0)
        {
            head=head->next;
            return head;
        }
        ListNode* te = head;
        while(te!=NULL)
        {
            tr--;
            if(tr==0)
            {
                ListNode* x = te->next;
                te->next=x->next;
                break;
            }
            te=te->next;

        }
        return head;
    }
};