
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
 // just pass count as -1 if height is f(edges), in this variant height is f(node)
class Solution {
public:
    int getHeight(TreeNode* node, int count) {
        if(!node) return count;
        
        int leftAns = getHeight(node->left, count+1);
        int rightAns = getHeight(node->right, count+1);
        return max(leftAns, rightAns);
        
    }
    int maxDepth(TreeNode* root) {
        return getHeight(root, 0); 
    }
};
