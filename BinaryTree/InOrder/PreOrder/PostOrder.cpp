
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
 
void inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return ;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        stack<TreeNode*> ans;
        st.push(root);
        while(!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            ans.push(top);
            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
            
        }
        while(!ans.empty()) {
            res.push_back(ans.top()->val);
            ans.pop();
        }
        return res;
    }
};
