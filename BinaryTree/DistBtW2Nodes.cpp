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
    /* Should return minimum distance between a and b
    in a tree with given root*/
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
    int findDis(Node* root, int k, int count) {
        if(!root) return -1;
        
        if(root->data == k) return count;
        
        int left = findDis(root->left, k, count+1);
        
        if(left == -1) return findDis(root->right, k, count+1);
        return left;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA = lca(root, a, b);
        
        int d1 = findDis(LCA, a, 0);
        int d2 = findDis(LCA, b, 0);
        
        return d1 + d2;
    }
};