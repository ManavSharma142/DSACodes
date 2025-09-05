// Programme to move zeroes to end of array
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array ";
    cin >> n;
    cout << endl;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element for array : ";
        cin >> arr[i];
        cout << endl;
    }

    cout << "The original array is " <<endl;
    for(auto i : arr) cout << i << " ";
    cout << endl;

    // Move zeroes at the end

    int nonZero = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) { 
            swap(arr[i], arr[nonZero]);
            nonZero++;
        }
    }

    cout << "The modified array is " <<endl;
    for(auto i : arr) cout << i << " ";

    return 0;

}
// 1 2 0 4 3 0 5 0