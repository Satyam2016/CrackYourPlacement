// Given a linked list of 0s, 1s and 2s, The task is to sort and print it.

// Examples: 

// Input: 1 -> 1 -> 2 -> 0 -> 2 -> 0 -> 1 -> NULL 
// Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> NULL

// Input: 1 -> 1 -> 2 -> 1 -> 0 -> NULL 
// Output: 0 -> 1 -> 1 -> 1 -> 2 -> NULL 

void sortList(Node *head) {
  int count[3] = {0, 0, 0};
 
  // Count the number of 0's, 1's, and 2's in the linked list
  Node *current = head;
  while (current != nullptr) {
    count[current->data]++;
    current = current->next;
  }
 
  // Overwrite the linked list with the sorted elements
  current = head;
  int i = 0;
  while (current != nullptr) {
    if (count[i] == 0) {
      i++;
    } else {
      current->data = i;
      count[i]--;
      current = current->next;
    }
  }
}