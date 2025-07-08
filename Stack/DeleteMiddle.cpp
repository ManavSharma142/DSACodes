#include<stack>
using namespace std;
class Solution {
  public:
    // Function to delete middle element of a stack.
    int getSize(stack<int> s) {
        int count = 0;
        while(!s.empty()) {
            count++;
            s.pop();
        }
        return count;
    }
    void solve(stack<int>& s, int count, int size) {
        if(count == size/2) {
            s.pop();
            return;
        }
        int val = s.top();
        s.pop();
        solve(s, count+1, size);
        s.push(val);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int count = 0;
        int size = getSize(s);
        solve(s, count, size);
    }
};