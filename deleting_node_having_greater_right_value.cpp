// Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immediate Right , but entire List on the Right)

// Example 1:

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:

// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
// Explanation: All the nodes except the last
// node has a greater value node on its right,
// so all the nodes except the last node must
// be removed.

class Solution {
public:
    Node *compute(Node *head) {
        // Reverse the list
        head = rev(head);

        int maxi = head->data;
        Node* pre = head;
        Node* temp = head->next;
        while (temp != NULL) {
            if (temp->data < maxi) {
                pre->next = temp->next;
                delete temp;
                temp = pre->next;
            } else {
                maxi = temp->data;
                pre = temp;
                temp = temp->next;
            }
        }

        // Reverse the list again to restore the original order
        return rev(head);
    }

    Node *rev(Node *head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* temp = NULL;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};