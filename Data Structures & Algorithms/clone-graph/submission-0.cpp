/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* create(Node* node,unordered_map<Node*,Node*>& mp)
    {
        Node* newNode=new Node(node->val);
        mp[node]=newNode;
        for(auto x:node->neighbors)
        {
            if(mp.find(x)==mp.end())
            {
               
                mp[x] =create(x,mp);
                newNode->neighbors.push_back(mp[x]);
            }
            else
            {
                newNode->neighbors.push_back(mp[x]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
        return nullptr;
        unordered_map<Node*,Node*> mp;
        return create(node,mp);
    }
};
