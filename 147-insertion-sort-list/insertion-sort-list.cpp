class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode revHead(std::numeric_limits<int>::max(), nullptr);

        // Inserting nodes one by one into a *reverse-sorted* list
        ListNode* insert = head;
        while (insert != nullptr) {
            int val = insert->val;
            ListNode* insertBehind = &revHead;
            while (insertBehind->next != nullptr && insertBehind->next->val > val) {
                insertBehind = insertBehind->next;
            }

            ListNode* nextInsert = insert->next;
            insert->next = insertBehind->next;
            insertBehind->next = insert;
            insert = nextInsert;
        }

        // Reversing the reverse-sorted list
        ListNode* prev = nullptr;
        ListNode* curr = revHead.next;
        while (true) {
            ListNode* next = curr->next;
            if (next == nullptr) {
                curr->next = prev;
                return curr; // This is the actual termination point of the function
            } else {
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        }

        return nullptr; // This should never happen
    }
};