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
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* temp = root;
        Node* pred = NULL;
        Node* succ = NULL;
        
        while(temp && temp->data != key) {
            if(temp->data > key) {
                succ = temp;
                temp = temp->left;
            }
            else{
                pred = temp;
                temp = temp->right;
            }
        }
        
        if(!temp) return {pred, succ};
        // predecessor
        if(temp->left) {
            Node* leftMax = temp->left;
            while(leftMax) {
                pred = leftMax;
                leftMax = leftMax->right;
            }
        }
        
        // succesor
        if(temp->right) {
            Node* rightMax = temp->right;
            while(rightMax) {
                succ = rightMax;
                rightMax = rightMax->left;
            }
        }
        return {pred, succ};
    }
};

class Solution {
  public:
    void f(Node* root, Node* &pred, Node* &succ, int key) {
        if(!root) return;
        
        f(root->left, pred, succ, key);
        
        if(root->data > key) {
            if(!succ || succ->data > root->data) succ = root;
        }
        else if(root->data < key) pred = root;
        
        f(root->right, pred, succ, key);
    } 
    vector<Node*> findPreSuc(Node* root, int key) { 
        // code here
        Node* pred = NULL, *succ = NULL;
        f(root, pred, succ, key);
        return {pred, succ};
    }
};