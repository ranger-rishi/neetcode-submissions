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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,int> m1;
        ListNode* pointer=head;
        while(true)
        {
            if(pointer==nullptr)
            return false;
            if(m1.find(pointer)==m1.end())
            {
                m1[pointer]++;
                pointer=pointer->next;
            }
            else
            return true;

        }
        // return true;
    }
};
