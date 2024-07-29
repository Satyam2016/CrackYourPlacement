// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevlast=NULL;
        ListNode* temp=head;
        while(temp){
           ListNode* kthnode=getKthNode(temp, k);
           if(kthnode==NULL){
            if(prevlast)
                 prevlast->next=temp;
            break;
           }
            ListNode* nextNode = kthnode -> next; 
            kthnode -> next = NULL; 
            rev(temp); 
    
            if(temp == head){
                head = kthnode;
            }else{
                prevlast -> next = kthnode; 
            }
            prevlast = temp; 
            temp = nextNode; 
        }
        return head;
    }
};