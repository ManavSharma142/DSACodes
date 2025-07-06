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
Node* LLToBST(Node*& head, int count) {
        // base case
        if( count <= 0 || !head) return NULL;
        
        Node* left = LLToBST(head, count/2);
        
        Node* root = new Node(head->data);
        root->left = left;
        head=head->right;
        
        root->right = LLToBST(head, count-count/2-1);
        return root;    
    }