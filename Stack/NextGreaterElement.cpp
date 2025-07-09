#include<stack>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n);
        ans[n-1] = -1;
        s.push(arr[n-1]);
        
        for(int i = arr.size() - 2; i >= 0; i--) {
            int ele = arr[i];
            
            while(!s.empty() && s.top() <= ele) s.pop();
            
            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(ele);
        }
        
        return ans;
    }
};