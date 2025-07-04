#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};



class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        while(root) {
            if(root->data < n1->data && root->data < n2->data) root = root->right;
            else if(root->data > n1->data && root->data > n2->data) root = root->left;
            else return root;
        } return NULL;
    }
};