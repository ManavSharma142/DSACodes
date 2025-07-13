#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
    bool areAnagrams(Node *root1, Node *root2) {
        // base checks
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        
        // Node->data, frequency
        unordered_map<int, int> mp;
        queue<Node*> q1, q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();
            
            if(n1 != n2) return false;
            
            while(n1--) {
                Node* front1 = q1.front();
                q1.pop();
                
                mp[front1->data]++;
                
                if(front1->left) q1.push(front1->left);
                if(front1->right) q1.push(front1->right);
            }
            
            while(n2--) {
                Node* front2 = q2.front();
                q2.pop();
                
                if(mp.find(front2->data) == mp.end()) return false;
                
                mp[front2->data]--;
                if(mp[front2->data] == 0) mp.erase(front2->data);
                
                if(front2->left) q2.push(front2->left);
                if(front2->right) q2.push(front2->right);
            }
            if(mp.size() > 0) return false;
        }
        if(!q1.empty() && !q2.empty()) return false;
        return true;
    }
};