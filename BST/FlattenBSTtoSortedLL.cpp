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
//using inorder
Node* flatten(Node* root) {
    vector<int> ans;

    // get inorder of root in ans

    Node* newRoot = new Node(ans[0]);
    Node* curr = root;

    for(int i = 1; i < ans.size(); i++) {
        Node* temp = new Node(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;

    }
    curr->left = curr->right = NULL;
    return newRoot; 
}


// another way : 
void BSTtoLL(Node*& root, Node*& head) {
        if(!root) return;
        
        BSTtoLL(root->right, head);
        root->right = head;
        if(head) head->left = root;
        
        head = root;
        BSTtoLL(root->left, head);
    } 