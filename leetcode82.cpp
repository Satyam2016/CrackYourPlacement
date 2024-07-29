// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* temp=head;
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }
        while(head){
            if(mp[head->val]!=1){
                head=head->next;
            }else{
                break;
            }
        }
        temp=head;
        ListNode* prev=NULL;
        while(temp){
            if(mp[temp->val]!=1){
                prev->next=temp->next;
                temp=temp->next;
            }else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};