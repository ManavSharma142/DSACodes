#include<bits/stdc++.h>
using namespace std;
int binarySearch(int *arr, int s, int e, int key) {
    while(s <= e) {
        int mid = s + (e - s) / 2;

        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) s = mid + 1;
        else e = mid - 1;
    
    }
    return -1;
}
int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Given Array is ";
    for(auto i : arr) cout << i << " ";
    
    int key ;
    cout << endl << "Enter key to search for ";
    cin >> key;
    
    int ans = binarySearch(arr, 0, n, key);
    if(ans  != -1)
        cout << "Element found at index " << ans;
    else 
        cout << "Element not found";

    return 0;
}