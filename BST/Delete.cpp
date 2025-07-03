

#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int minVal(TreeNode* root) {
        TreeNode* temp = root;
        while(temp->left) temp = temp->left;
        return temp->val;
    }
    TreeNode* delUtil(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key) {
            // 2 child exists
            if(root->left && root->right) {
                int mini = minVal(root->right);
                root->val = mini;
                root->right = delUtil(root->right, mini);
                return root;
            }
            // only right child exists
            else if(root->right && !root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // only left child exists
            else if(!root->right && root->left) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            // leaf node
            else {
                delete root;
                return NULL;
            }
        }
        else if(root->val < key) {
            root->right = delUtil(root->right, key);
            return root;
        }
        else {
            root->left = delUtil(root->left, key);
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delUtil(root, key);
    }
};