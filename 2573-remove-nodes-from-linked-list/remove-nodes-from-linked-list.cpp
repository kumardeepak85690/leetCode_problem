class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr = prev->next;
        prev->next = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            if (curr->val >= prev->val) {
                curr->next = prev;
                prev = curr;
            }
            curr = temp;
        }

        return prev;
    }
};