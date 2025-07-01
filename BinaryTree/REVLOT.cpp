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
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        queue<Node*> q;
        stack<int> st;
        q.push(root);
        while(!q.empty()) {
            
            Node* top = q.front();
            q.pop();
            st.push(top->data);
            
            if(top->right) q.push(top->right);
            if(top->left) q.push(top->left);
            
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    
    }
};