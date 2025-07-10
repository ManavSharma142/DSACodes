#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        
        for(auto i : s) {
            
            if(i == '(' || i == '+' || i == '-' || i == '*' || i == '/') 
                st.push(i);
                
            else{
                if(i == ')') {
                    bool isRedun = true;
                    while(!st.empty() && st.top() != '(') {
                        char ch = st.top();
                        st.pop();
                        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
                            isRedun = false;
                    }
                    if(isRedun) return 1;
                    st.pop();
                }
            }
        } 
        return 0;
    }
};
