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
    /*You are required to complete this method*/
    bool check(Node *root) {
        // Your code here
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int leafLevel = -1;
        
        while(!q.empty()) {
            pair<Node*, int> p = q.front();
            q.pop();
            
            Node* frontNode = p.first;
            int level = p.second;
            
            if(!frontNode->left && !frontNode->right) {
    
                if(leafLevel == -1) leafLevel = level;
                else if(leafLevel != level) return false;
            }
            if(frontNode->left) q.push({frontNode->left, level+1});
            if(frontNode->right) q.push({frontNode->right, level+1});
        }
        
        return true;
    }
};