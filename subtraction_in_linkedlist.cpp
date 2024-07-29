// You are given two linked lists that represent two large positive numbers. These two numbers are represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

// Example 1:

// Input:
// L1 = 1->0->0
// L2 = 1->2
// Output: 88
// Explanation:  
// First linked list represents 100 and the
// second one represents 12. 12 subtracted from 100
// gives us 88 as the result. It is represented
// as 8->8 in the linked list.
// Example 2:

// Input:
// L1 = 0->0->6->3
// L2 = 7->1->0
// Output: 647
// Explanation: 
// First linked list represents 0063 => 63 and 
// the second one represents 710. 63 subtracted 
// from 710 gives us 647 as the result. It is
// represented as 6->4->7 in the linked list.


class Solution {
public:
    Node* rev(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* temp=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node* subtract(Node* head1, Node* head2){
        Node* dummyhead= new Node(0);
        Node* temp=dummyhead;
         int diff=0, borrow=0;
        while(head1){
            diff=head1->data-(head2? head2->data: 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            temp->next=new Node(diff);
            temp=temp->next;
            
            head1=head1->next;
            if(head2) head2=head2->next;
            
        }
        Node* result=rev(dummyhead->next);
        delete dummyhead;
        
        while (result && result->data == 0) {
            Node* toDelete = result;
            result = result->next;
            delete toDelete;
        }
        
        return result ? result : new Node(0);
    }
    
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1!=NULL && head1->data==0){
            head1=head1->next;
        }
        while(head2!=NULL && head2->data==0){
            head2=head2->next;
        }
        
        int len1=0, len2=0;
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1){
            len1++;
            temp1=temp1->next;
        }
        while(temp2){
            len2++;
            temp2=temp2->next;
        }
        if(len1<len2){
            swap(head1, head2);
        }else if(len1==len2){
            temp1=head1;
            temp2=head2;
            while(temp1 && temp2){
                if(temp1->data<temp2->data){
                    swap(head1, head2);
                    break;
                }
                else if (temp1->data > temp2->data) {
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        head1=rev(head1);
        head2=rev(head2);
        return subtract(head1, head2);
        
    }
};