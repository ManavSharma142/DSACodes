#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    
    int toSumTree1(Node *node) 
{ 
    // Base case 
    if(node == NULL) 
    return 0; 

    // Store the old value 
    int old_val = node->data; 

    // Recursively call for left and
    // right subtrees and store the sum as 
    // old value of this node 
    node->data = toSumTree1(node->left) + toSumTree1(node->right); 

    // Return the sum of values of nodes
    // in left and right subtrees and 
    // old_value of this node 
    return node->data + old_val; 
} 
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
        int v = toSumTree1(node);
    }
};