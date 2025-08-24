// merge 2 linked list
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void InsertatTail(ListNode* &tail , int d){
    ListNode* temp = new ListNode(d);
    tail -> next = temp;
    tail = temp;
}
void printLL(ListNode* head) {
    if(!head) return ;

    ListNode* temp = head;
    while(temp) {
        cout << temp->val << " ";
        temp=temp->next;
    }

    return;
}

ListNode* merge2LL(ListNode* first, ListNode* second) {
    
    if(!first) return second;
    if(!second) return first;
    
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    while(first && second) {
        if(first->val <= second->val) {
            temp->next = first;
            temp = first;
            first=first->next;
        }
        else {
            temp->next = second;
            temp=second;
            second=second->next;
        }
    }
    while(first) {
        temp->next = first;
        temp = first;
        first=first->next;
    }
    while(second) {
        temp->next = second;
        temp=second;
        second=second->next;
    }
    return ans->next;
}
int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* tail1 = head1;
    InsertatTail(tail1, 3);
    InsertatTail(tail1, 7);
    InsertatTail(tail1, 17);

    ListNode* head2 = new ListNode(15);
    ListNode* tail2 = head2;
    InsertatTail(tail2, 21);
    InsertatTail(tail2, 92);
    InsertatTail(tail2, 177);

    printLL(head1);
    cout << endl;
    printLL(head2);
    cout << endl;

    ListNode* newH = merge2LL(head1, head2);
    printLL(newH);
    cout << endl;
    return 0;
}
