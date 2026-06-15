// head2->val=head->val;
// head2->next=head->next;
// head2->random=head2->random;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// actually we can have another map which maps the original list to our list 
// or do we need it ->yes we need it 
// is that sufficient though?? ->yes it is 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return nullptr;
        Node* head2=new Node(head->val);
       
        
        Node* sc=head2;
        unordered_map<Node*,Node*> m1;
        m1[head]=sc;
        while(head!=nullptr)
        {
            if(head->next && m1.find(head->next)==m1.end())
            {
                // m1[head->next]++;
                Node* scrap=new Node(head->next->val);
                m1[head->next]=scrap;
                sc->next=scrap;
            }
            else
            {
                if(m1.find(head->next)!=m1.end())
                {
                    auto it = m1.find(head->next);
                    sc->next=it->second;
                }
            }
            if(head->random && m1.find(head->random)==m1.end())
            {                
                Node* scrap=new Node(head->random->val);
                m1[head->random]=scrap;
                sc->random=scrap;
                // cout<<1<<endl;
            }
            else
            {
                if(m1.find(head->random)!=m1.end())
                {
                    auto it = m1.find(head->random);
                    sc->random=it->second;
                    // cout<<2<<endl;
                }
            }
            head=head->next;
            sc=sc->next;
        }
        return head2;
    }
};
