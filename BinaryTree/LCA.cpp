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
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        if(!root) return NULL;
        
        if(root->data == n1 || root->data == n2) return root;
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(!leftAns && !rightAns) {
            return NULL;
        }
        else if(leftAns && rightAns) return root;
        
        else if(leftAns && !rightAns) return leftAns;
        
        else return rightAns;
    }
};



