

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
                TreeNode* temp = root->left;
                delete root;
                return temp;
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

TreeNode* insertIntoBST(TreeNode* root , int data){
    //base case
    if(!root){
        root= new TreeNode(data);
        return root;
    }
    if(data>root->val) root->right = insertIntoBST(root->right , data);
    //right insert
        
    else root->left = insertIntoBST(root->left , data);
    //left insert
    
    return root ;
}
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->val <<" ";
            if ( temp->left ){
                q.push(temp->left);
            }
            if ( temp->right ){
                q.push(temp->right);
            }
        }
    }
}