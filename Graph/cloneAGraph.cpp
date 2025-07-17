
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


class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloned) {
        if(!node) return NULL;

        if(cloned.find(node) != cloned.end()) return cloned[node];

        Node* newNode = new Node(node->val);

        cloned[node] = newNode;

        for(Node* nbr : node->neighbors) {
            newNode->neighbors.push_back(dfs(nbr, cloned));
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloned;
        return dfs(node, cloned);
    }
};