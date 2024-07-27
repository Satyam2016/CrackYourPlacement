// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* res= dummy;
        int carry=0; 
        l1=rev(l1);
        l2=rev(l2);
        while(l1 || l2 || carry){
            int sum=0;
            sum+= (l1)? l1->val : 0;
            sum+= (l2)? l2->val : 0;
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            res->next=temp;
            res=res->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        rev(l1);
        rev(l2);
        return rev(dummy->next);
    }

    ListNode* rev(ListNode* head){
        ListNode* temp=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};