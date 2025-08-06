#include<iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[n] = {0, 1, 2, 3, 4, 5, 6, 7};
    int a = 2;
    int b = 7;

    cout << "Original array: ";
    for(auto i : arr) cout << i << " ";

    cout << endl;

    while(a+1 < b-1) {
        swap(arr[a+1], arr[b-1]);
        a++;
        b--;
    }

    cout << "Swapped array: ";
    for(auto i : arr) cout << i << " ";
    cout << endl;
}