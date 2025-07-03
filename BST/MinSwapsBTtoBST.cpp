#include<bits/stdc++.h>
using namespace std;
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; 
void inorder(vector<int>& inorderBST, vector<int>& arr, int index) {
        if(index >= arr.size()) return;
        
        inorder(inorderBST, arr, 2*index+1);
        
        inorderBST.push_back(arr[index]);
        
        inorder(inorderBST, arr, 2*index+2);
    }
    int minSwaps(vector<int>& arr) {
        // Write your code here
        vector<int> inorderBST;
        inorder(inorderBST, arr, 0);
        
        vector<pair<int, int>> t(inorderBST.size());
        int ans = 0;
        
        // Store the value and its index
        for (int i = 0; i < inorderBST.size(); i++)
            t[i] = {inorderBST[i], i};
        
        // Sort the pair array based on values 
      	// to get BST order
        sort(t.begin(), t.end());
        
        // Find minimum swaps by detecting cycles
        for (int i = 0; i < t.size(); i++) {
          
            // If the element is already in the 
          	// correct position, continue
            if (i == t[i].second)
                continue;
            
            // Otherwise, perform swaps until the element
          	// is in the right place
            else {
              
                // Swap elements to correct positions
                swap(t[i].first, t[t[i].second].first);
                swap(t[i].second, t[t[i].second].second);
            }
            
            // Check if the element is still not
          	// in the correct position
            if (i != t[i].second)
                --i;  
            
            // Increment swap count
            ans++;
        }
      
        return ans;
    }