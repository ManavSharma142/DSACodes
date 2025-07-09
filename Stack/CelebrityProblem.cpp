#include<bits/stdc++.h>
using namespace std;
// Bf 
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            bool isCeleb = true;
            
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    if(mat[i][j] == 1 || mat[j][i] == 0){
                        isCeleb = false;
                        break;
                    }
                }
            }
            if(isCeleb) return i;
        }
        
        return -1;
    }
};



// On On stack approach :
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int> s;
        
        for(int i = 0;i < n; i++) {
            s.push(i);
        }
        
        while(s.size() != 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(mat[a][b] == 1) s.push(b);
            else s.push(a);
        }
        
        int candidate = s.top();

        for(int i = 0 ; i <n ; i++) {
            if(i == candidate) continue;
            
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0 ) return -1;
        }
        return candidate;
    
    }
};


// On O1 approach : 2 pointers
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int i = 0; int j = n-1;
        
        while(i < j) {
            if(mat[i][j]) i++;
            else j--;
        }
        
        int candidate = i;

        for(int i = 0 ; i <n ; i++) {
            if(i == candidate) continue;
            
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0 ) return -1;
        }
        return candidate;
    
    }
};