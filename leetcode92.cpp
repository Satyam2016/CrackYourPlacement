// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head) return NULL;
        if (left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;

        for (int i = 1; i < left; ++i) {
            before = before->next;
        }

        ListNode* l = before->next;
        ListNode* r = l->next;

        for (int i = 0; i < right - left; ++i) {
            l->next = r->next;
            r->next = before->next;
            before->next = r;
            r = l->next;
        }

        return dummy->next;
    }
};