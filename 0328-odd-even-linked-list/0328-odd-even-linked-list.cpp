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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* h = head;
        ListNode* temp = head->next;
        ListNode* temp2 = head->next;

        while(temp2!=NULL && temp2->next!=NULL)
        {
            head->next=temp2->next;
            head=head->next;
            temp2->next=head->next;
            temp2=temp2->next;
        }
        head->next=temp;
        return h;

        
    }
};