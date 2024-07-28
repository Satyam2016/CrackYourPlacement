// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2){
        if (!h1) return h2;
        if (!h2) return h1;
        
        ListNode* head = new ListNode(0); 
        ListNode* current = head;

        while (h1 && h2) {
            if (h1->val < h2->val) {
                current->next = h1;
                h1 = h1->next;
            } else {
                current->next = h2;
                h2 = h2->next;
            }
            current = current->next;
        }
        
        if (h1) current->next = h1;
        if (h2) current->next = h2;
        
        ListNode* mergedHead = head->next;
        delete head; 
        return mergedHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode* head=NULL;
        
        for(int i=0; i<n; i++){
            head=merge(head, lists[i]);
        }
        return head;
    }
};