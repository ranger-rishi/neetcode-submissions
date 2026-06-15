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
    void reorderList(ListNode* head) {
        // i don't want to create a new stack since it would mean modifying the original nodes or would it ??
        // a node is defined by it's two attributes the next pointer and its value 
        // so in the end we are changning the next pointers so the node is solely determined by its value, and maybe the memory location of this 
        // by creating a new heap i would create new memory addresses , can i do that ? /
        // anyways i would have to create new memory addresses for them is it allowed though , ?
        //We can divide the list into two halves using the fast and slow pointer approach,
        // which helps identify the midpoint of the list. 
        //This allows us to split the list into two halves,
        // with the heads labeled as l1 and l2. Next, we reverse the second half (l2).
        // After these steps, we proceed to reorder the two lists by iterating 
        //through them node by node, updating the next pointers accordingly.
        //sweet
        ListNode* fast;
        ListNode* slow;
        ListNode* x;
        if(head==nullptr)
        return ;
        if(head->next==nullptr)
        return ;
        if(head->next->next==nullptr)
        return ;
        slow=fast=head;
        while( fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        // slow=slow->next;
        cout<<slow->val<<endl;
        cout<<fast->val<<endl;
        // now reverse a node starting flow slow;
        //okay so now my slow pointer is at the point where i want to reverse the list 
        ListNode* head2=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        ListNode* clear=head2;
        ListNode* z;
        while(true)
        {
            z=clear->next;
            clear->next=prev;
            prev=clear;
            if(z)
            clear=z;
            else
            break;
         }
        // cout<<clear->val<<endl;
        // cout<<clear->next->val<<endl;
        head2=clear;
        ListNode* y;
        y=head;
        ListNode* g;
        while(true)
        {
            if(y)
            z=y->next;
            if(head2)
            g=head2->next;
            if(y)
            y->next=head2;
            if(head2)
            head2->next=z;
            y=z;
            head2=g;
            if(head2==nullptr && y==nullptr)
            break;
        }
        return;
    }
};
