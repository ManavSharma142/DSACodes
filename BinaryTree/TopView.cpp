#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        if(!root) return {};
        queue<pair<Node*, int>> q; // Node to horizontal distance
        map<int, int> mp; // horizontal distnace -> node->data
        
        q.push({root, 0});
        while(!q.empty()) {
            pair<Node*, int> topNode = q.front();
            q.pop();
            Node* frontNode = topNode.first;
            int hd = topNode.second;
            
            if(mp.find(hd) == mp.end()) mp[hd] = frontNode->data;
            
            if(frontNode->left) q.push({frontNode->left, hd - 1});
            if(frontNode->right) q.push({frontNode->right, hd + 1});
        }
        
        vector<int> ans;
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};