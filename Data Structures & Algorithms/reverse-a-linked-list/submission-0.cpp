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
        if(head==nullptr)
        return nullptr;
        ListNode* x;
        x=head;
        ListNode* prev=nullptr;
        ListNode* z;
        while(true)
        {
            if(x->next==nullptr)
            {
                x->next=prev;
                return x;
            }
            z=x->next;
            x->next=prev;
            prev=x;
            x=z;
        }        
    }
};
