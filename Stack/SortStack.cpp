#include<bits/stdc++.h>
using namespace std;


class SortedStack{
public:
    stack<int> s;
    void sort();
};


/* The below method sorts the stack s
you are required to complete the below method */
void sortedInsert(stack<int>& s, int ele) {
    if(s.empty() || (!s.empty() && s.top() < ele)) {
        s.push(ele);
        return;
    }
    int val = s.top();
    s.pop();
    sortedInsert(s, ele);
    s.push(val);
}
void SortedStack ::sort() {
    // Your code here
    if(s.empty()) return;
    
    int ele = s.top();
    s.pop();
    
    sort();
    sortedInsert(s, ele);
}