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
    void dfs(Node* node,Node* root,map<Node*,Node*> &visited){
        if(!node) return;
        visited[node]=root;
        for(Node* nbr: node->neighbors){
            // node has not been created yet
            if(visited.find(nbr)==visited.end()){
                Node* currNbr = new Node(nbr->val);
                root->neighbors.push_back(currNbr);
                dfs(nbr,currNbr,visited);
            }else{
                Node* newNbr = visited[nbr];
                root->neighbors.push_back(newNbr);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* root = new Node(1);
        map<Node*,Node*> visited;
        // do a dfs to create copy
        dfs(node,root,visited);
        return root;
    }
};
