class MinStack {
public:
    // Node* head ;
    stack<int> s;
    struct Node{
        Node* next;
        int value;
        Node(int val)
        {
            value=val;
            next=nullptr;
        }
    };
    Node* head;
    MinStack() {
        head = nullptr;
    }    
    void push(int val) {
        if(head==nullptr)
        {
            s.push(val);
        }
        else
        {
           int x= s.top();
           s.push(min(x,val));
        }
        Node* newNode= new Node(val);
        if(head==nullptr)
        {
            head=newNode;
        }
        else{
        newNode->next=head;
        head=newNode;
        }
    }
    
    void pop() {
        if(head==nullptr)
        return;
        s.pop();
        Node* scrap = head;
        head=head->next;
        scrap->next=nullptr;
        delete scrap;
    }
    
    int top() {
        if(head==nullptr)
        return -1;
        else
        return head->value;
    }
    
    int getMin() {
        if(s.size()==0)
        return -1;
        else
        return s.top();
    }
};
