struct Node{
    Node* next;
    Node* prev;
    int val;
    Node()
    {
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
    //so we want to use a doubly linked list + an unordered_map
    // what do we do , we make a variable and update it everytime an element is added 
    // 

public:
int cap =0;
int i = 0 ;
Node* head=nullptr;
Node* tail=nullptr;
unordered_map<int,int> m1;
    void update(int key)
    {
        //we just have to bring this forward
        Node* nc=head;
        while(nc->val!=key)
        {
            nc=nc->next;
        }
        if(nc==tail && tail!=head)
        {
            tail=tail->prev;
        }
        if(nc==head)
        return;
        // now we have nc->val= key 
        Node* x= nc->prev;
        Node* y = nc->next;
        if(y==nullptr)
        {
            x->next=y;
        }
        else
        {
            x->next=y;
            y->prev=x;
        }
        nc->next=head;
        head->prev=nc;
        nc->prev=nullptr;
        head=nc;
    }
    void add(int key)
    {
        // if(head==nullptr)
        Node* newNode= new Node();
        newNode->val=key;
        if(head==nullptr)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    void del()
    {
        if(head==nullptr)
        return;
        else
        {
            Node* nc= tail;
            if(nc==head)
            {
                m1.erase(m1.find(head->val));
                tail=nullptr;
                head=nullptr;
                delete nc;
                return;
            }
            tail=tail->prev;
            tail->next=nullptr;
            nc->prev=nullptr;
            m1.erase(m1.find(nc->val));
            delete nc;
            return;
        }
    }
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m1.find(key)==m1.end())
        {
            return -1;
        }
        else
        {
            update(key);
            return m1[key];
        }
    }
    
    void put(int key, int value) {
        if(i==cap && m1.find(key)==m1.end())
        {
            del();
            add(key);
            m1[key]=value;
        }
        else if (i==cap)
        {
            update(key);
            m1[key]=value;
        }
        else
        {
            if(m1.find(key)==m1.end())
            {
                i++;
                add(key);
                m1[key]=value;
            }
            else
            {
                update(key);
                m1[key]=value;
            }
        }
    }
};
