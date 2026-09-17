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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        int cnt = n;
        dummy.next = head;
        while (cnt) {
            fast = fast->next;

            cnt--;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // temp = slow->next;
        slow->next = slow->next->next;

        return dummy.next;
    }
};