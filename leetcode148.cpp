// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

 class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(), arr.end());
    
        ListNode* dummy=new ListNode(0);
        temp=dummy;
        for(int i=0; i<arr.size();i++){
            ListNode* node=new ListNode(arr[i]);
            temp->next=node;
            temp=temp->next;
        }

        while (head) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        
        ListNode* sortedHead = dummy->next;
        delete dummy; 
        return sortedHead;
    }
};