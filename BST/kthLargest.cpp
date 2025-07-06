#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    int Inorder(Node* root, int& count, int key) {
        if(!root) return -1;
        
        int right = Inorder(root->right, count, key);
        
        if(right!=-1) return right;
        
        count++;
        
        if(count == key) {
            return root->data;
        }
        
        return Inorder(root->left, count, key);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int count = 0;
        return Inorder(root, count, k);
    
    }
};