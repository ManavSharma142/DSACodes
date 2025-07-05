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
    // using Morris Traversal to flatten BST
    Node* flattenBST(Node* root) {
        Node* curr = root;
        Node* prev = NULL;
        Node* newRoot = NULL;
    
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Link current node to the previous node in in-order
                if (prev != nullptr) {
                    prev->right = curr;
                } else {
                    newRoot = curr; // This is the first (leftmost) node
                }
                curr->left = nullptr;
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                Node* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
    
                // Make curr the right child of its inorder predecessor
                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Restore original tree structure
                    pred->right = nullptr;
    
                    if (prev != nullptr) {
                        prev->right = curr;
                    } else {
                        newRoot = curr;
                    }
                    curr->left = nullptr;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
    
        return newRoot;
    }

};