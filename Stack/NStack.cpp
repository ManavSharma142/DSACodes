#include <bits/stdc++.h> 
class NStack
{
    int* arr;
    int* top;
    int* next;

    int n, s;

    int freespot;
public:
    
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i = 0 ; i < n; i++) {
            top[i] = -1;
        }

        for(int i = 0; i < s-1; i++) {
            next[i] = i+1;
        }
        //update last index to -1
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freespot == -1) return false;

        //find index
        int idx = freespot;

        //update freespot
        freespot = next[idx];

        //insert element
        arr[idx] = x;

        //update next
        next[idx] = top[m-1];

        //update top
        top[m-1] = idx;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1) return -1;

        int idx = top[m-1];

        top[m-1] = next[idx];

        next[idx] = freespot;

        freespot = idx;

        return arr[idx];
    }
};