#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    void f(Node* root, vector<int>& ans, int level) {
        if(!root) return;
        
        if(level == ans.size()) ans.push_back(root->data);
        
        f(root->left, ans, level+1);
        f(root->right, ans, level+1);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        f(root, ans, 0);
        return ans;
    }
};