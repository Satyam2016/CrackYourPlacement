// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

class Solution {
public:
    void reorderList(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        int mid=(len%2==0)? len/2: len/2 + 1;
        ListNode* second;
        temp=head;
        int i=0;
        while(temp){
            i++;
            if(i==mid){
                second=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
        ListNode* pre=NULL;
        ListNode* curr=second;
        temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        second=pre;
        temp=head;
        ListNode* nextElement;
        while(second){
            nextElement=second->next;
            second->next=temp->next;
            temp->next=second;
            second=nextElement;
            temp=temp->next->next;
        }
    }
};