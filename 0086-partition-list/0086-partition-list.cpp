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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode DummyLess(0);
        ListNode* lesstail = &DummyLess;
        ListNode DummyGreater(0);
        ListNode* GreaterTail = &DummyGreater;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = nullptr;

            if (curr->val < x) {
                lesstail->next = curr;
                lesstail = curr;
               
            } else {
                GreaterTail->next = curr;
                GreaterTail = curr;
             
            }
            curr = next;
        }
        lesstail->next = DummyGreater.next;
        return DummyLess.next;
    }
};