//Programme to swap second and last node of a linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* swapSecondAndLast(Node*& head) {
    if(!head || !head->next || !head->next->next) return head; 

    Node* second = head->next;
    Node* afterSecond = second->next;

    second->next = NULL;
    Node* Secondlast = head;
    while(Secondlast->next->next) Secondlast = Secondlast->next; 
    Node* last = Secondlast->next;
    Secondlast->next = NULL;

    head->next = last;
    last->next = afterSecond;
    Secondlast->next = second;

    return head;   
}
void InsertatTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}
void printLL(Node* head) {
    if(!head) return ;

    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp=temp->next;
    }

    return;
}
int main() {
    Node* head = new Node(1);
    Node* tail = head;

    InsertatTail(tail, 2);
    InsertatTail(tail, 3);
    InsertatTail(tail, 4);
    InsertatTail(tail, 5);

    printLL(head);
    cout << endl;

    head = swapSecondAndLast(head);
    printLL(head);

    return 0;
}

