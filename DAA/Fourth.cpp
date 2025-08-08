// Write a programme to implement mergeSort and find its time complexity also
#include<bits/stdc++.h>
using namespace std;
vector<int> mergeSort(vector<int>& arr) {
    if(arr.size() <= 1) return arr;
    
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    vector<int> merged;
    int i = 0, j = 0;
    
    while(i < left.size() && j < right.size()) {
        if(left[i] < right[j]) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }
    
    while(i < left.size()) {
        merged.push_back(left[i++]);
    }
    
    while(j < right.size()) {
        merged.push_back(right[j++]);
    }
    
    return merged;
}
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    vector<int> sortedArr = mergeSort(arr);

    cout << "Original Array : " << endl;
    for(auto i : arr) cout << i << " ";
    cout << endl;
    cout << "Sorted Array : " << endl;
    for(auto i : sortedArr) cout << i << " ";

    return 0;
}
