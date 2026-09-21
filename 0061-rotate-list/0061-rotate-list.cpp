/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        k = k % n;
        if (k == 0)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};