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
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    string dupSub_Util(Node* root, unordered_set<string>& s, int &ans) {
        
        if(!root) return "N";
        
        if(!root->left && !root->right) return to_string(root->data);
        
        string curr = "";
        curr += to_string(root->data);
        
        string left = dupSub_Util(root->left, s, ans);
        string right = dupSub_Util(root->right, s, ans);
        
        if(left != "" && right != "") {
            curr += '*';
            curr += left;
            curr += '*';
            curr += right;
        }
        else{
            return "";
        }
        if(s.find(curr) != s.end()) ans = 1;
        else s.insert(curr);
        
        return "";
    }
    int dupSub(Node *root) {
        // code here
        unordered_set<string> s;
        int ans = 0;
        dupSub_Util(root, s, ans);
        return ans;
    }
};