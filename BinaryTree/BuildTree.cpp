#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node* solve( map<int, int>& mp, vector<int> &inorder, vector<int> &preorder, int& index, int InOrderStart, int InOrderEnd, int n) {
        // base case
        if(index >= n || InOrderStart > InOrderEnd) return nullptr;
        
        int element = preorder[index++];
        Node* root = new Node(element);
        
        int pos = mp[element];

        root->left = solve(mp, inorder, preorder, index, InOrderStart, pos-1, n);
        root->right = solve(mp, inorder, preorder, index, pos+1, InOrderEnd, n );
        
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0;
        int n = inorder.size();
        
        map<int, int> mp ; // node tom index
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        Node* ans = solve(mp, inorder,preorder , preOrderIndex, 0, inorder.size()-1, n);
        return ans;
    }
};






// from inorder and postorder
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    Node* solve( map<int, int>& mp, vector<int> &inorder, vector<int> &postorder, int& index, int InOrderStart, int InOrderEnd, int n) {
        // base case
        if(index < 0 || InOrderStart > InOrderEnd) return nullptr;
        
        int element = postorder[index--];
        Node* root = new Node(element);
        
        int pos = mp[element];

        
        root->right = solve(mp, inorder, postorder, index, pos+1, InOrderEnd, n );
        root->left = solve(mp, inorder, postorder, index, InOrderStart, pos-1, n);
        return root;
        
    }
    Node *buildTreeUtil(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int postOrderIndex = postorder.size()-1;
        int n = inorder.size();
        
        map<int, int> mp ; // node tom index
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        Node* ans = solve(mp, inorder,postorder , postOrderIndex, 0, inorder.size()-1, n);
        return ans;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        return buildTreeUtil(inorder, postorder);
    }
};