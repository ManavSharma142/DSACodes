#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;



Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


// Brute Force solution : n square, n 
class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    int getPos(int element, int pre[], int size, int index) {
        
        int pos = -1;
        for(int i = index+1; i < size; i++) {
            while(pre[i] < element) {
                pos = i;
                i++;
            }
        }
        return pos;
    }
    Node* Util(int& index, int pre[], int size, int preOrderStart, int preOrderEnd) {
        if( index >= size || preOrderStart > preOrderEnd) return nullptr;
        
        int element = pre[index];
        Node* root = newNode(element);
        int pos = getPos(element, pre, size, index);
        index++;
        
        if(pos != -1) {
            root->left = Util(index, pre, size, preOrderStart, pos);
            root->right = Util(index, pre, size, pos+1, preOrderEnd);
        }
        else{
            root->right = Util(index, pre, size, index, preOrderEnd);
        }
        
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int preOrderStart = 0;
        int preOrderEnd = size - 1;
        
        int index = 0;
        return Util(index, pre, size, preOrderStart, preOrderEnd);
    }
};



// optimised soln : 
// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Util(int& index, int pre[], int size, int mini, int maxi) {
        if( index >= size || pre[index] < mini || pre[index] > maxi) return nullptr;
        
        Node* root = newNode(pre[index++]);
        root->left = Util(index, pre, size, mini, root->data);
        root->right = Util(index, pre, size, root->data, maxi);
        
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int index = 0;
        return Util(index, pre, size, mini, maxi);
    }
};