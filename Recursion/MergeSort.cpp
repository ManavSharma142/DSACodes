#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int merge(vector<int> &arr, int s, int mid, int e) {
        int count = 0;
        int l1 = mid - s + 1;
        int l2 = e - mid;

        int* first = new int[l1];
        int* second = new int[l2];

        int k = s;
        for (int i = 0; i < l1; i++) {
            first[i] = arr[k++];
        }

        k = mid + 1;
        for (int i = 0; i < l2; i++) {
            second[i] = arr[k++];
        }

        int i = 0, j = 0;
        k = s;

        while (i < l1 && j < l2) {
            if (first[i] <= second[j]) {
                arr[k++] = first[i++];
            } else {
                arr[k++] = second[j++];
                count += l1 - i; // actual inversion count
            }
        }

        while (i < l1) arr[k++] = first[i++];
        while (j < l2) arr[k++] = second[j++];

        delete[] first;
        delete[] second;

        return count;
    }

    int mergeSort(vector<int> &arr, int s, int e) {
        if (s >= e) return 0;

        int mid = s + (e - s) / 2;
        int leftInv = mergeSort(arr, s, mid);
        int rightInv = mergeSort(arr, mid + 1, e);
        int mergeInv = merge(arr, s, mid, e);

        return leftInv + rightInv + mergeInv;
    }
};