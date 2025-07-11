#include<bits/stdc++.h>
using namespace std;

class KQueue{
    
    public:
        int n;
        int k;
        int* front;
        int* rear;
        int* arr;
        int* next;
        int freespot;

        KQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];

            for(int i = 0 ; i < k; i++) {
                rear[i] = -1;
                front[i] = -1;
            }

            next = new int[n];

            for(int i = 0 ; i < n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freespot = 0;

        }

        void enqueue(int data, int qn) {
            if(freespot == -1) {
                cout << "Overflow" << endl;
                return;
            }
            else{
                int idx = freespot;
                freespot = next[idx];

                //check whether first element
                if(front[qn-1] == -1) front[qn-1] = idx;

                else{
                    // link new eleemnt to previous elemtn
                    next[rear[qn-1]] = idx;

                }

                next[idx] = -1;
                rear[qn-1] = idx;
                arr[idx] = data;

            }
            return;
        }

        int dequeue(int qn) {
            if(front[qn-1] == -1) {
                cout<<"Underflow"<<endl;
                return -1;
            }
            else{
                int idx = front[qn-1];
                front[qn-1] = next[idx];
                //freespots ko manage karo
                next[idx] = freespot;
                freespot = idx;
                return arr[idx];
            }
            
        }

};

int main() {

    KQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(2) << " ";
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(1) << " ";
    return 0;
}