#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        int size = q.size();
        queue<int> q1;
        queue<int> q2;
        int count = 0;
        while(count < size/2) {
            q1.push(q.front());
            q.pop();
            count++;
        }
        while(!q.empty()) {
            q2.push(q.front());
            q.pop();
        }
        
        for(int i = 0; i < size/2; i++) {
            q.push(q1.front());
            q1.pop();
            q.push(q2.front());
            q2.pop();
        }
        return q;
    }
};