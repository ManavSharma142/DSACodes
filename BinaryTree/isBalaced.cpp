#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// for brute force soln, do 3 conditions, isBalanced(left) && isBalanced(right) && abs(getHeight(root->left) - getHeight(root->right) <= 1)
// optimised solution : 
class Solution {
  public:
    pair<bool, int> isBalancedUtil(Node* root) {
        if(!root) return {true, 0};
        
        pair<bool, int> left = isBalancedUtil(root->left);
        pair<bool, int> right = isBalancedUtil(root->right);
        pair<bool, int> ans;
        
        ans.first = left.first && right.first;
        ans.second = max(left.second, right.second) + 1;
        
        if(left.first && right.first && (abs(left.second - right.second) <= 1 )) return ans;
        else return {false, ans.second};
        
    }
    bool isBalanced(Node* root) {
        // Code here
        return isBalancedUtil(root).first;
    }
};