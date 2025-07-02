#include<bits/stdc++.h>
using namespace std;
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    void TraverseLeft(Node* root, vector<int>& ans) {
        if(!root || (!root->left && !root->right)) return;
        
        ans.push_back(root->data);
        if(root->left) TraverseLeft(root->left, ans);
        else TraverseLeft(root->right, ans);
    }
    void TraverseLeaf(Node* root, vector<int>& ans) {
        if(!root ) return;
        if(!root->left && !root->right)
            ans.push_back(root->data);
        TraverseLeaf(root->left, ans);
        TraverseLeaf(root->right, ans);
    }
    void TraverseRight(Node* root, vector<int>& ans) {
        if(!root || (!root->left && !root->right)) return;
        
        if(root->right) TraverseRight(root->right, ans) ;
        else TraverseRight(root->left, ans);
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return {};
        
        vector<int> ans;
        ans.push_back(root->data);
        // left
        TraverseLeft(root->left, ans);
        
        //leaf
        
        //left leaf nodes
        TraverseLeaf(root->left, ans);
        //right leaf
        TraverseLeaf(root->right, ans);
        
        // traverse right
        TraverseRight(root->right, ans);
        
        return ans;
    } 
};