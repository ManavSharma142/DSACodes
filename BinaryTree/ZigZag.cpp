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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        bool leftToRight = 1;

        q.push(root);
        while(!q.empty()) {
            
            int size = q.size();
            vector<int> temp(size);

            for(int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                int idx = leftToRight ? i : size - i - 1;
                temp[idx] = frontNode->val;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};