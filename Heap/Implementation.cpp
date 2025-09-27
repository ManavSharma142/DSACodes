#include<bits/stdc++.h>
using namespace std;
// implementing Max Heap using 0 based index
// node is i, parent is i-1 / 2, left child 2i + 1, right 2i + 2
class Heap{
    int* arr;
    int size = 0;
    int n;
    Heap(int n) {
        this->n = n;
        arr = new int[n];
    }
// below code is heapify up 
    void insertInHeap(int val) {
        if(size == n) {
            cout << "Heap is full" << endl;
            return;
        }
        int index = size;
        arr[index] = val;
        size++;
        while(index > 0) {
            int parent = (index-1)/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else break;
        }
        
        cout <<" Element Added Successfully" << endl;
        return;
    }
    //heapify dowwn
    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[0] = arr[size-1];
        size--;
        int i = 0;
        while(i < size) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < size && arr[left] > arr[i]) {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if(right < size && arr[right] > arr[i]) {
                swap(arr[right], arr[i]);
                i = right;
            }
            else break;
        }
        cout << "Element Deleted Successfully" << endl;
        return;
    }
    
};

void Heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest= left;
    if(right < n && arr[right] > arr[largest]) largest= right;
    if(largest!= i) {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}
vector<int> HeapSort(vector<int>& nums) {
    int n = nums.size();
    // Build MaxHeap
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(nums, n, i);
    }
    // Swap, decremnt (for loop will handle), Heapify
    for (int i = n - 1; i > 0; i--) {
        swap(nums[i], nums[0]);
        Heapify(nums, i, 0); // Correct call: i is the new size
    }
    return nums;
}