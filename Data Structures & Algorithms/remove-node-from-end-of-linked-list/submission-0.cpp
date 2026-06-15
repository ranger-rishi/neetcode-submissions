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
        ListNode* fast=head;
        ListNode* slow=head;
        if(head->next==nullptr)
        return nullptr;
        // i want to be at nth position from the last make the distance between them to be n
        int i = n;
        while(i--)
        {
            fast=fast->next;
        }
        if(fast==nullptr)
        {
            head=head->next;
            return head;
        }
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        if(fast)
        cout<<fast->val<<endl;
        cout<<slow->val<<endl;
        //we are open position before the element we want to delete
        ListNode* y = slow->next;
        slow->next=slow->next->next;
        y->next=nullptr;
        delete y ;
        return head;
    }

};
