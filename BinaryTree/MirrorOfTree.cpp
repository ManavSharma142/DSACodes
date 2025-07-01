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
    TreeNode* mirrorify(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* mirror = new TreeNode(root->val);
        mirror->left = mirrorify(root->right);
        mirror->right = mirrorify(root->left);
        return mirror;
    }
    TreeNode* invertTree(TreeNode* root) {
        return mirrorify(root);
    }
};

class Solution {
public:
    TreeNode* f(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left) f(root->left);
        if(root->right) f(root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return f(root);
    }
};