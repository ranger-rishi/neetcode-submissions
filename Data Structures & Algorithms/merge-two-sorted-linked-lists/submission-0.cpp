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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* x;
        if(list1==nullptr)
        return list2;
        if(list2==nullptr)
        return list1;
        ListNode* y;
        ListNode* z;
        ListNode* w=nullptr;
        y=list1;
        z=list2;
        int flag=0;
        if(y->val>z->val)
        {
            w=z;
            z=z->next;
        }
        else
        {
            w=y;
            y=y->next;
        }
        x=w;
        while(true)
        {
            if(y==nullptr)
            {w->next=z;
            break;}
            if(z==nullptr)
            {
                w->next=y;
                break;
            }
            if(y->val>z->val)
            {
                w->next=z;
                z=z->next;
            }
            else
            {
                w->next=y;
                y=y->next;
            }
            w=w->next;
        }

        return x;
    }
};
