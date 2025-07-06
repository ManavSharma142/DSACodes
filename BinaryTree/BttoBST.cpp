#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};


class Solution {
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void Inorder(Node* root, vector<int>& inorder) {
        
        if(!root) return;
        Inorder(root->left, inorder);
        
        inorder.push_back(root->data);
        
        Inorder(root->right, inorder);
    }
    void UpdateBt(Node* root, vector<int>& inorder, int& index) {
        if(!root) return;
        
        UpdateBt(root->left, inorder, index);
        
        root->data = inorder[index++];
        
        UpdateBt(root->right, inorder, index);
    }
    Node *binaryTreeToBST(Node *root) {
        // Your code goes here
        vector<int> inorder;
        Inorder(root, inorder);
        
        sort(inorder.begin(), inorder.end());
        int index = 0;
        UpdateBt(root, inorder, index);
        return root;
    }
};