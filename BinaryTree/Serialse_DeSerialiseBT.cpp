#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void ser_Util(Node* root, vector<int>& ans) {
        if(!root) {
            ans.push_back(-1);
            return ;
        }
        
        ans.push_back(root->data);
        ser_Util(root->left, ans);
        ser_Util(root->right, ans);
    }
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> ans;
        ser_Util(root, ans);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node* deSer_Util(vector<int>& arr, int& i) {
        // base case
        if(arr[i] == -1) {
            i++;
            return nullptr;
        }
        Node* root = new Node(arr[i]);
        i++;
        root->left = deSer_Util(arr, i);
        root->right = deSer_Util(arr, i);
        
        return root;
    }
    Node *deSerialize(vector<int> &arr) {
        int i = 0;
        return deSer_Util(arr, i);
        
    }
};