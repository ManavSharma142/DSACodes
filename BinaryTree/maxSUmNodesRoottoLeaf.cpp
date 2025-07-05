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
    void solve(Node* root, int len, int &maxLen, int sum, int& maxSum) {
        if(!root) {
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if(maxLen == len) maxSum = max(sum, maxSum);
            return ;
        }
        
        sum += root->data;
        
        solve(root->left, len+1, maxLen, sum, maxSum);
        solve(root->right, len+1, maxLen, sum, maxSum);
    } 
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int len = 0, maxLen = 0;
        int maxSum = INT_MIN, sum = 0;
        
        solve(root, len, maxLen, sum, maxSum);
        return maxSum;
    }
};