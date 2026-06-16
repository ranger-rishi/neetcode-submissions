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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode* head=new ListNode();
        priority_queue<pair<int,ListNode*>> pq;
        int n = lists.size();
        if(n==0)
        return nullptr;
       //maybe i can have a priority queue in which i can initially push all of them and then while
       // removing check which index does it belong to
       // and advance the head of that index;
       // and then add the head of that index again
       // and keep repeating this till the pq is empty 
       // okay this is sweet ,works in logn 
       // overall it takes O(nlogn) 
       // wow , how am i so intelligent
        for(int i=0;i<n;i++)
        {
            pq.push({-1*(lists[i]->val),lists[i]});
        }
        ListNode* prev=nullptr;
        ListNode* head=nullptr;
        while(!pq.empty())
        {
            ListNode* scrap;
            scrap=(pq.top()).second;
            ListNode* scrap2;
            scrap2=scrap->next;
            if(!prev)
            {
                head=scrap;
                prev=head;
            }
            else
            {
                prev->next=scrap;
                prev=prev->next;
            }
            pq.pop();
            if(scrap2)
            {
                pq.push({-1*(scrap2->val),scrap2});
            }
            else 
            continue;
        }
        return head;
    }
};
