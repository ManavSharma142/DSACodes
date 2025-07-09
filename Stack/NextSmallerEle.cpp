#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(arr[n-1]);
    vector<int> ans(n) ;
    ans[n-1] = -1;
    for(int i = n-2 ; i>=0 ; i--){
        int curr = arr[i];
        while(!s.empty() && s.top()>=curr){
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else{
            ans[i]=s.top();
        }
        
        s.push(curr);
    }
    return ans ; 
}