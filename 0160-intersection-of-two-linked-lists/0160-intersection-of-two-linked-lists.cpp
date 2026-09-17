/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* start = headA;
        ListNode* end = headB;
        while (start != end) {
            if (start == nullptr) {
                start = headB;
            } else {
                start = start->next;
            }

            if (end == nullptr) {
                end = headA;
            } else {
                end = end->next;
            }
        }
        return start;
    }
};