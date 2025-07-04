#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
  public:
    void RevInOrder(Node*& root, Node*& forward) {
        if(!root) return;
        
        RevInOrder(root->right, forward);
        
        if(!forward) forward = root;
        else{
            root->next = forward;
            forward = root;
        }
        
        RevInOrder(root->left, forward);
    }
    void populateNext(Node *root) {
        
        Node* forward = NULL;
        RevInOrder(root, forward);
    }
};