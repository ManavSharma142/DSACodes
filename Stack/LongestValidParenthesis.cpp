#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        int len = 0;
        int lastInvalid = -1;
        
        for(int i = 0 ; i <s.length(); i++) {
            if(s[i] == '(' ) st.push(i);
            else {
                if(!st.empty()) {
                    st.pop();
                    if(st.empty()) {
                        len  = i - lastInvalid;
                    }
                    else{
                        len = i - st.top();
                    }
                    ans = max(ans, len);
                }
                else{
                    lastInvalid = i;
                }
            }
        }
        return ans;
    }
};