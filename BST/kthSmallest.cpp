/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
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
    // Return the Kth smallest element in the given BST
    int Inorder(Node* root, int& count, int key) {
        if(!root) return -1;
        
        int left = Inorder(root->left, count, key);
        
        if(left!=-1) return left;
        
        count++;
        
        if(count == key) {
            return root->data;
        }
        
        return Inorder(root->right, count, key);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        int count = 0;
        return Inorder(root, count, k);
    }
};