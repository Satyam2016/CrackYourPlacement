// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

 class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        if(!head->next) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=rev(slow->next);
        ListNode* first=head;
        ListNode* second=newhead;

        while(second!=NULL){
            if(first->val!=second->val){
                slow->next=rev(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        slow->next=rev(newhead);
        return true;
    }
    ListNode* rev(ListNode* head){
        ListNode* temp=NULL;
        ListNode* prev=NULL; 
        ListNode* curr=head;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};