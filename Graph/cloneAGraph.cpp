
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


// using bfs
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    unordered_map<Node*, Node*> cloned;
    queue<Node*> q;

    // Step 1: Clone the starting node
    Node* cloneStart = new Node(node->val);
    cloned[node] = cloneStart;
    q.push(node);

    // Step 2: BFS traversal
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        for (Node* neighbor : curr->neighbors) {
            if (!cloned.count(neighbor)) {
                // Clone neighbor
                cloned[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }
            // Connect cloned neighbor to current clone
            cloned[curr]->neighbors.push_back(cloned[neighbor]);
        }
    }

    return cloneStart;
}
