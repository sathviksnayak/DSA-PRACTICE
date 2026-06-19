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
    unordered_map<Node*,Node*> map;
    Node* dfs(Node* node){
        if(!node) return nullptr;
        if(map.find(node)!=map.end()){
            return map[node];
        }
        Node* newnode=new Node(node->val);
        map[node]=newnode;

        for(Node* n:node->neighbors){
            newnode->neighbors.push_back(dfs(n));
        }

        
    return newnode;
    }
    Node* cloneGraph(Node* node) {
        
        return dfs(node);

    }
};