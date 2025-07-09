
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n);
        ans[0] = -1;
        s.push(0);
        
        for(int i = 1; i < n; i++) {
            int ele = arr[i];
            while(!s.empty() && arr[s.top()] >= ele) s.pop();
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }