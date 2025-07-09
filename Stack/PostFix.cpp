#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for (auto i : arr) {
            string str = i;

            // Check if it's an operator
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();
                
                switch(str[0]) {
                    case '+': st.push(val1 + val2); break;
                    case '-': st.push(val1 - val2); break;
                    case '*': st.push(val1 * val2); break;
                    case '/': st.push(val1 / val2); break;
                }
            } else {
                // Else it's a number (can be negative or multi-digit)
                st.push(stoi(str));
            }
        }
        
        return st.top();
    }
};
