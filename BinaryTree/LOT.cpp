#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution{ 
vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
      
        vector<int> v;
        while(!q.empty()) {
            
            Node* top = q.front();
            q.pop();
            
            if(top == NULL) {
                res.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                v.push_back(top->data);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return res;
    }
};