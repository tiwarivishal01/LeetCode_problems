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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        ListNode* A = List1;
        ListNode* B = List2;
        while (A != nullptr && B != nullptr) {
            if (A->val <= B->val) {
                temp->next = A;
                temp = A;
                A = A->next;
            } else if (A->val > B->val) {
                temp->next = B;
                temp = B;
                B = B->next;
            }
        }

        if (A != nullptr)
            temp->next = A;
        else
            temp->next = B;

        return dummy.next;
    }
};