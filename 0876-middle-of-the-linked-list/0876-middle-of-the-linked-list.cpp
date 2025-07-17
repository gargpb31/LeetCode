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
    int lengt(ListNode* head)
    {
        int ans = 0;
        while(head!=nullptr)
        {
            ans++;
            head=head->next;
        }
        return ans;
    }

    ListNode* mid(ListNode* head)
    {
        ListNode* headcopy = head;
        int length = lengt(headcopy);
        
        if(length%2==0)
        {
                int midd = (length+2)/2;

                int y = 1;
                while(y!=midd)
                {
                    head=head->next;
                    y++;
                }
                return head;
        }
        
            int midd  = (length+1)/2;
                int y = 1;
                while(y!=midd)
                {
                    head=head->next;
                    y++;
                }
                return head;
        
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* headcopy = head;
        int length = lengt(headcopy);
        
        if(length%2==0)
        {
                int midd = (length+2)/2;

                int y = 1;
                while(y!=midd)
                {
                    head=head->next;
                    y++;
                }
                return head;
        }
        
            int midd  = (length+1)/2;
                int y = 1;
                while(y!=midd)
                {
                    head=head->next;
                    y++;
                }
                return head;
    }
};