#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

class Solution {
  public:
    pair<int, int> diaFast(Node* root) {
        if(!root) return {0, -1};
        
        pair<int, int> left = diaFast(root->left);
        pair<int, int> right = diaFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 2;
        
        pair<int, int> ans;
        ans.first = max({op1, op2, op3});
        ans.second = max(left.second, right.second) + 1;
        // we are doing +2 to handle height (accounts for 2 edges connecting root to its children)
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        return diaFast(root).first;
    }
};