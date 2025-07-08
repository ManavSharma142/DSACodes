
// Approach 1 : Fixing memory for 2 stacks 
class twoStacks {
  public:
  
    int arr[200];
    int top1;
    int top2;
    twoStacks() {top1 = -1; top2 = 200;}
    
    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1 < 99) {
            top1++;
            arr[top1] = x;
            return;
        }
        else return;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        
        if(top2 > 100) {
            top2--;
            arr[top2] = x;
            return;
        }
        else return;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(top1 >= 0) {
            int val = arr[top1];
            top1--;
            return val;
        }
        else return -1;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 < 200) {
            int val = arr[top2];
            top2++;
            return val;
        }
        else return -1;
    }
};



// Not fixing memory 

class twoStacks {
  public:
    int* arr;
    int top1;
    int top2;
    int size;
    
    twoStacks(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = x;
            
        }
        return;
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = x;
        }
        return;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(top1 == -1) return -1;
        else{
            int val = arr[top1];
            top1--;
            return val;
        }
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == size) return -1;
        else{
            int val = arr[top2];
            top2++;
            return val;
        }
    }
};