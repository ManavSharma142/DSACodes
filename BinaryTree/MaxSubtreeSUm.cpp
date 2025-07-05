#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find largest subtree sum.
    int solve(Node* root, int& ans) {
        if(!root) return 0;
        
        int sum = root->data;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        
        if(sum + left + right > ans) ans = sum + left + right;
        
        return sum + left + right;
    }
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
