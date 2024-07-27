// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        temp=head;
        if(n==len) return head->next;
        int i=0;
        while(temp){
            if(i+1==len-n){
                if(temp->next->next){
                    temp->next=temp->next->next;
                }else{
                    temp->next=NULL;
                    break;
                }
            }
            i++;
            temp=temp->next;
        }
        return head;
    }
};