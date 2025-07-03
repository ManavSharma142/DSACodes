/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
    void inOrder(Node* curr, Node*& head, Node*& prev) {
        if(!curr) return;
        
        inOrder(curr->left, head, prev);
        if(!prev) head = curr;
        else{
            prev->right = curr;
            curr->left = prev;
        }
        prev = curr;
        inOrder(curr->right, head, prev);
    }
    Node* bToDLL(Node* root) {
        // code here
        Node* head = nullptr;
        Node* prev = nullptr;
        inOrder(root, head, prev);
        return head;
    }
};