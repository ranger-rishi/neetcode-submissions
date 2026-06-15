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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev=nullptr;
        ListNode* head=nullptr;
        while(l1 || l2)
        {
            int x= l2?l2->val:0;
            int y = l1?l1->val:0;
            int sum=(x+y+carry) % 10;
            carry = (x+y+carry)/10;
            cout<<sum<<endl;
            ListNode* node= new ListNode(sum);
            if(prev)
            {
                prev->next=node;
            }
            else
            {
                 head=node;
            }
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            prev=node;
        }
        if(carry)
        {
            prev->next=new ListNode(carry);
        }
        return head;
    }
};
