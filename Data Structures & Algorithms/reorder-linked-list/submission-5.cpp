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
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;

    // 1. Find middle (slow will be mid)
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Split (second starts after mid)
    ListNode* second = slow->next;
    slow->next = nullptr;

    // 3. Reverse second half
    ListNode* prev = nullptr;
    while (second != nullptr) {
        ListNode* next1 = second->next;
        second->next = prev;
        prev = second;
        second = next1;
    }

    second = prev;

    // 4. Merge
    ListNode* first = head;
    while (second != nullptr) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
};
