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
    pair<ListNode*,ListNode*> reverse(ListNode* head)
    {
       ListNode* sc=head;
       ListNode* prev=nullptr;
       if(!head)
       return {nullptr,nullptr};
       while(sc)
       {
        ListNode* x= sc->next;
        sc->next=prev;
        prev=sc;
        sc=x;
       }
       return {prev,head};
    }
    ListNode* helper(ListNode* head,int k)
    {
        int i = k;
        ListNode* sc=head;
        while(--i)
        {
            if(sc)
            sc=sc->next;
            else 
            break;
        }
        if(i!=0 || !sc)
        return head;
        ListNode* head2=sc->next;
        sc->next=nullptr;

        ListNode* front= reverse(head).first;
        ListNode* back=reverse(head).second;
        // cout<<front->val<<" "<<back->val<<" "<<head2->val<<" "<<endl;
        back->next=helper(head2,k);
        return front;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       return helper(head,k);
    }
};
