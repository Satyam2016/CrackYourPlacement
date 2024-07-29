// Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
// For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

// Note: It is recommended do this in-place without altering the node's values.

// Example 1:

// Input:
// LinkedList: 1->2->3
// Output: 1 3 2
// Explanation:
// Here n=3, so the correct
// order is A0→A2→A1
// Example 2:

// Input:
// Explanation: 1->7->3->4
// Output: 1 4 7 3
// Explanation:
// Here n=4, so the correct
// order is A0→A3→A1→A2

class Solution{ 
public:

    Node* rev(Node* head){
        Node* curr=head;
        Node* temp=NULL;
        Node* prev=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(Node* head) {
        // Your code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* second=rev(slow->next);
        slow->next=NULL;
        Node* first=head;
        Node * temp=NULL;
        while(second){
            temp = first->next;
            first->next = second;
            first = first->next;
            second = second->next;
            first->next = temp;
            first = first->next;
        }
    }
};