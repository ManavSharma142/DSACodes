#include<bits/stdc++.h>
using namespace std ;
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

void QueueStack ::push(int x) {
    // code here
    q1.push(x);
    return;
}

int QueueStack ::pop() {

    if(q1.empty()) return -1;
    else{
        while(q1.size() != 1) {
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }
        int val = q1.front();
        q1.pop();
        while(!q2.empty() ) {
            q1.push(q2.front());
            q2.pop();
        }
        
        return val;
    }
}