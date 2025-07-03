// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Brute Force Solution
class Solution {
  public:
    // function to construct tree from string
    int findIdx(string s, int i, int j) {
        
        if(i > j) return -1;
        
        int count = 0;
        for(int k = i; k <= j; k++) {
            
            if(s[k] == '(') count++;
            
            else if(s[k] == ')')  {
                count--;
                if(count == 0) return k;
            }
        }
        
        return -1;
    }
    Node* solve(string s, int i, int j) {
        
        if(i > j) return nullptr;
        // finding value of root
        int val = 0;
        
        while(i <= j && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            val = val*10 + digit;
            i++;
        }
        
        Node* root = new Node(val);
        int idx = -1;
        
        if(i<= j && s[i] == '(') idx = findIdx(s, i, j);
        
        if(idx != -1) {
            root->left = solve(s, i+1, idx - 1);
            
            root->right = solve(s, idx+2, j - 1);
        }
        return root;
        
    }
    Node *treeFromString(string str) {
        // code here
        return solve(str, 0, str.length()-1);
    }
};

// Optimised Soln 

class Solution {
  public:
    // function to construct tree from string
    Node* Optimised(string& s, int& i) {
        // based on preorder
        if(s[i] == ')') return nullptr;
        
        int val = 0;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            val = val*10 + digit;
            i++;
        }
        Node* root = new Node(val);
        
        if(i < s.length() && s[i] == '(') {
            i++; // to jump over opening bracket
            root->left = Optimised(s, i);
            i++; // to jump over closing bracketof that child
        }
        if(i < s.length() && s[i] == '(') {
            i++;
            root->right = Optimised(s, i);
            i++;
        }
        return root;
    }
    Node *treeFromString(string str) {
        // code here
        int i = 0;
        return Optimised(str, i);
    }
};