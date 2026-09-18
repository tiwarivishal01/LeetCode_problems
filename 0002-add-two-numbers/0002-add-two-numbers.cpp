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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int carry = 0;

        while (t1 != nullptr || t2 != nullptr || carry != 0) {
            int dig1 = (t1 != nullptr) ? t1->val : 0;
            int dig2 = (t2 != nullptr) ? t2->val : 0;
            
            int sum = dig1 + dig2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            if (t1 != nullptr) t1 = t1->next;
            if (t2 != nullptr) t2 = t2->next;
        }

        return dummy->next;
    }
};