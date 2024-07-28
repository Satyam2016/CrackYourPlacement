// // Given a Linked List of integers, 
// write a function to modify the linked list such that
//  all even numbers appear before all the odd numbers 
//  in the modified linked list.
//   Also, keep the order of even and odd numbers the same.

class Node 
{ 
public: 
    int data; 
    Node *next; 
    Node (int d) {
        data = d;
        next = nullptr;
    }
}; 


Node* segregateEvenOdd(struct Node* head)
{
    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    
    Node* currNode = head;

    while (currNode != nullptr) {
        int val = currNode->data;
        if (val % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }
        else {
            if (oddStart == nullptr) {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }
        currNode = currNode->next;
    }

    if (oddStart == nullptr || evenStart == nullptr)
        return;

    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    return evenStart;
}