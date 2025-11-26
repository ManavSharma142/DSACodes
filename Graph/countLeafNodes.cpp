// recursive programme to count total number of leaf nodes in a binary tree
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution{
    int countLeafNodes(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
};