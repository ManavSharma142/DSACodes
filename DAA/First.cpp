#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int k = 2;
    int n = 5;

    int temp[5];  // temp array to store rotated elements
    cout << "Shifting by " << k << "positions to the left:"<<endl;
    for(int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n]; // shift left by k
    }

    // copy back to original array
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    for(int i = 0 ;i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr2[5] = {1, 2, 3, 4, 5};
    k = 2;
    n = 5;

    int temp2[5];
    cout << "Shifting by " << k << " positions to the right:" << endl;
    for(int i = 0; i < n; i++) {
        temp2[(i + k) % n] = arr2[i];  // shifting right
    }

    for(int i = 0; i < n; i++) {
        arr2[i] = temp2[i];
    }

    for(int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
