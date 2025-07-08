#include<iostream>
using namespace std ; 
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
    ~Node(){
        
        if ( next != NULL){
            delete next;
            next= NULL;
        }
    }
};

class Stack{
    private:
    Node* top;
    public:
    Stack(){
        // Can also write "NULL" in place of "nullptr"
        this->top = nullptr ;   
    }
    void push( int data){
        Node* temp = new Node(data);
        temp->next = top;
        top = temp ; 
    }
    void pop(){
        if ( top == NULL){
            cout<<"Stack Underflow"<<endl;
            return ; 
        }
        else{
            Node* save = top->next;
            top->next = NULL ;
            delete top ; 
            top = save ; 
        }
    }
    bool isEmpty(){
        if(top==NULL){
            return 1;
        }
        else{
            return 0 ; 
        }
    }
    int peak(){
        if(!isEmpty()) return top->data; 
        
        else return -1;
    }
};
int main(){
    Stack s;
    s.push(5);
    s.push(8);
    s.push(3);
    cout<<s.peak()<<endl;;
    s.pop();
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack isn't empty"<<endl;
    }
    s.pop();
    cout<<s.peak()<<endl;;
    s.pop();
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack isn't empty"<<endl;
    }
    s.pop();
    return 0;
    

}