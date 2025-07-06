#include<bits/stdc++.h>
using namespace std;
 
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
    void Inorder(Node* root, vector<int>& inOrder) {
        if(!root) return;
        
        Inorder(root->left ,inOrder);
        inOrder.push_back(root->data);
        Inorder(root->right, inOrder);
    }
    Node* InorderToBST(vector<int>& inOrder, int s, int e) {
        if(s > e) return nullptr;
        
        int mid = s + (e-s) / 2;
        
        Node* root = new Node(inOrder[mid]);
        root->left = InorderToBST(inOrder, s, mid - 1);
        root->right = InorderToBST(inOrder, mid+1, e);
        
        return root;
    }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> inOrder;
        Inorder(root, inOrder);
        
        int inOrderStart = 0;
        int inOrderEnd = inOrder.size()-1;
        return InorderToBST(inOrder, inOrderStart, inOrderEnd);
    }
};