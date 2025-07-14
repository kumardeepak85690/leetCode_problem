class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while (head != nullptr) {
            num = (num << 1) | head->val;
            head = head->next;
        }
        return num;
    }
};