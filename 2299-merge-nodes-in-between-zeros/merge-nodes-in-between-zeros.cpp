class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Initialize a dummy node to help with edge cases
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        ListNode* current = head->next; // Start from the node after the initial zero
        int sum = 0;

        while (current != nullptr) {
            if (current->val == 0) {
                // When we encounter a zero, it signifies the end of a segment
                if (sum != 0) {
                    // Create a new node with the sum and add it to the result list
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                    sum = 0; // Reset the sum for the next segment
                }
            } else {
                // Add the current node's value to the sum
                sum += current->val;
            }
            current = current->next;
        }

        return dummy.next; // The first node in the dummy list is the start of the result list
    }
};