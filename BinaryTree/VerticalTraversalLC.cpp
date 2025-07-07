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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // prepare required data structures

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        // Do L.O.T
        q.push({root, {0, 0}});
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].insert(frontNode->val);

            if(frontNode->left) q.push({frontNode->left, {hd-1, level+1}});
            if(frontNode->right) q.push({frontNode->right, {hd+1, level+1}});
        }

        for(auto i : nodes) {
            vector<int> temp;
            for(auto j : i.second) {
                for(auto k : j.second) {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};