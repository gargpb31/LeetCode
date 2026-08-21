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
    ListNode* reverse(ListNode* temp)
    {
        if(temp==NULL ||temp->next==NULL)
        {
            return temp;
        }

        ListNode* newnode = reverse(temp->next);

        ListNode* front = temp->next;

        front->next = temp;
        temp->next = NULL;

        return newnode;

    }

    bool isPalindrome(ListNode* head) {
        

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp = reverse(slow);
        while(head!=NULL && temp!=NULL)
        {
            if(temp->val!=head->val) return false;
            temp=temp->next;
            head=head->next;
        }

        return true;
    }
};