class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {

            if (temp->val == val) {
                // Skip the current node
                prev->next = temp->next;
                temp = temp->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};