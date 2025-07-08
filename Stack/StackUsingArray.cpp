
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


void MyStack ::push(int x) {
    
    if(top == 999) return;
    
    else {
        top++;
        arr[top] = x;
        return;
    }
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    
    if(top >= 0) {
        int val = arr[top];
        top--;
        return val;
    }
    else return -1;
}