#include <bits/stdc++.h> 
using namespace std;
int partition(vector<int>& arr ,int s , int e ) {
    int pivot = arr[s];
    int cnt=0;
    for (int i = s+1  ; i <= e ; i++){
        if (arr[i]<=pivot){
            cnt++;
        }
    }
    int pivotindex = s + cnt ;
    // place pivot at right position
    swap(arr[pivotindex] , arr[s]);
    // left right sambhalo 
    int i=s;
    int j=e;
    while(i<pivotindex && j> pivotindex){
        while ( arr[i]<=pivot){
            i++;
        }
        while ( arr[j]>pivot){
            j--;
        }
        if ( i<pivotindex && j> pivotindex){
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotindex;
}
void quickSort1(vector<int>& arr , int s , int e ) {
    //base case
    if ( s>=e ){
        return ;
    }
    //partition creating
    int p = partition(arr , s, e);
    //left part sort
    quickSort1(arr , s, p-1);
    //right part sort
    quickSort1(arr , p+1 , e);   
}
vector<int> quickSort(vector<int> arr)
{
    quickSort1(arr, 0, arr.size()-1);
    return arr;
}
