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
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* result = dummy;
        int n1 = 0;
        int n2 = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                n2 = l2->val;
                l2 = l2->next;
            }
            int res = n1 + n2 + carry;
            int val = res % 10;
            carry = res / 10;
            dummy->next = new ListNode(val);
            dummy = dummy->next;

            n1 = 0;
            n2 = 0;
        }

        if (carry > 0) dummy->next = new ListNode(carry);

        return result->next;
    }
};
