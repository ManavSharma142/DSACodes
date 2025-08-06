#include<bits/stdc++.h>
using namespace std;
void builtTree(int* tree, int* arr, int idx, int s, int e) {
    if(s > e) return;
     
    // leaf node
    if (s == e) {
        tree[idx] = arr[s];
        return;
    }

    int mid = s + (e-s)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    builtTree(tree, arr, left, s, mid);
    builtTree(tree, arr, right, mid+1, e);
    tree[idx] = min(tree[left], tree[right]); 
}
int query(int* tree, int idx, int s, int e, int qs, int qe) {
    if(s > e || qs > qe || qs > e || qe < s) return INT_MAX;
    if(qs <= s && qe >= e) return tree[idx];

    int mid = s + (e-s)/2;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int left_query = query(tree, left, s, mid, qs, qe);
    int riht_query = query(tree, right, mid+1, e, qs, qe);

    return min(left_query, riht_query);
}
int main() {
    int arr[] = {1, 3, 2, -2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* tree = new int[4*n];
    builtTree(tree, arr, 0, 0, n-1);
    int qs = 0;
    int qe = 1;
    cout << "Min ele in range " << qs << " to " << qe << " is:" << query(tree, 0, 0, n-1, qs, qe);
}