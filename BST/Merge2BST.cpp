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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void BSTtoLL(Node*& root,Node*& prev, Node*& head) {
        if (!root) return;
        
        BSTtoLL(root->left, prev, head);
        
        if (!prev) {
            head = root;  // First node in inorder
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;

        BSTtoLL(root->right, prev, head);
    } 
    Node* merge2LL(Node* head1, Node* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        
        Node* head = NULL, *tail = NULL;
        
        while(head1 && head2) {
            if(head1->data < head2->data) {
                if(!head) {
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                }
                else{
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1=head1->right;
                }
            }
            else{
                if(!head) {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else{
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2=head2->right;
                }
            }
        }
        while(head1) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
        while(head2) {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
        
        return head;
    }
    int count(Node* head) {
        int count = 0;
        while(head) {
            count++;
            head = head->right;
       }
       return count;
    }
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
    void inorder(Node* root, vector<int>& ans) {
        if(!root) return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
        
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        // step 1: convert bst to sorted dll inplace 
        Node* head1 = NULL, *prev1 = NULL;
        BSTtoLL(root1, prev1, head1);
        if(head1) head1->left = NULL;
        
        Node* head2 = NULL, *prev2 = NULL;
        BSTtoLL(root2, prev2, head2);
        if(head2) head2->left = NULL;
        
        // step 2: merge sorted LL
        
        Node* head = merge2LL(head1, head2);
        
        // convert sorted Ll to BST
        int cnt = count(head);
        
        Node* newRoot = LLToBST(head, cnt);
        
        vector<int> ans;
        inorder(newRoot, ans);
        return ans;
        
    }
};