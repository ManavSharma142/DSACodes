#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<long long> tree;

    void builtTree(vector<int>& baskets, int node, int s, int e) {
        if(s > e) return;
        
        // leaf node
        if (s == e) {
            tree[node] = baskets[s];
            return;
        }

        int mid = s + (e-s)/2;
        int left = 2*node + 1;
        int right = 2*node + 2;
        builtTree( baskets, left, s, mid);
        builtTree( baskets, right, mid+1, e);
        tree[node] = max(tree[left], tree[right]); 
    }

    void update(int node, int s, int e, int idx, int val) {
        if(s == e) {
            tree[node] = val;
            return;
        }

        int mid = s + (e-s)/2;
        if(idx <= mid) update(2 * node + 1, s, mid, idx, val);
        else update(2 * node + 2, mid+1, e, idx, val);

        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
        
    }
    int query(int node, int start, int end, int required_capacity) {
        if (tree[node] < required_capacity) {
            return -1;
        }
        if (start == end) {
            return start;
        }

        int mid = start + (end - start) / 2;
        int result = -1;

        // Prioritize searching the left child (2*node + 1)
        if (tree[2 * node + 1] >= required_capacity) {
            result = query(2 * node + 1, start, mid, required_capacity);
        }

        if (result != -1) {
            return result;
        }

        // Otherwise, search the right child (2*node + 2)
        if (tree[2 * node + 2] >= required_capacity) {
             result = query(2 * node + 2, mid + 1, end, required_capacity);
        }
       
        return result;
    }
    public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();
        tree.assign(4 * n, 0);
        // Initial call starts at the root node, which is index 0
        builtTree(baskets, 0, 0, n - 1);

        int unplaced_count = 0;
        for (int fruit_quantity : fruits) {
            // Initial query starts at the root node, index 0
            int basket_idx = query(0, 0, n - 1, fruit_quantity);

            if (basket_idx != -1) {
                // Initial update starts at the root node, index 0
                update(0, 0, n - 1, basket_idx, -1);
            } else {
                unplaced_count++;
            }
        }

        return unplaced_count;
    }
};