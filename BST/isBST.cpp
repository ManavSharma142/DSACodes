#include<bits/stdc++.h>
using namespace std;
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; 
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool util(Node* root, int minVal, int maxVal) {
        if(!root) return true;
        if(root->data <= minVal || root->data >= maxVal) return false;
        
        return (util(root->left, minVal, root->data)) && (util(root->right, root->data, maxVal));
    }
    bool isBST(Node* root) {
        // Your code here
        return util(root, INT_MIN, INT_MAX);
    }
}; // use LLONGMIN, LLONGMAX instead of intmin intmax to avoid overflow 