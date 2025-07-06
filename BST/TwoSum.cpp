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
    void Inorder(Node* root, vector<int>& arr) {
        if(!root) return;
        
        Inorder(root->left, arr);
        
        arr.push_back(root->data);
        
        Inorder(root->right, arr);
    }
    bool findTarget(Node *root, int target) {
        
        vector<int> arr;
        
        Inorder(root, arr);
        int left = 0;
        int right = arr.size()-1;
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            
            if(sum < target) left++;
            
            else if(sum > target) right--;
            
            else return true;
        }
        return false;
    }
};