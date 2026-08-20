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

    int count(ListNode* head)
    {
        int ct=0;
        while(head!=nullptr)
        {
            ct++;
            head=head->next;
        }
        return ct;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int ct = count(head);
        int tr=ct/2+1;

        while(temp!=nullptr)
        {
            if(tr==1) return temp;
            temp=temp->next;
            tr--;
        }
        return temp;
    }
};