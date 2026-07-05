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
    ListNode* ReverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* next1 = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next1;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revHead = ReverseList(head);

        // Get (n-1)th node
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        prev->next = revHead;
        ListNode* curr = revHead;
        int iLoop = 1;
        while (iLoop <= n) {
            if (iLoop == n) {
                prev->next = curr->next;
                curr->next = nullptr;
            } else {
                prev = curr;
                curr = curr->next;
            }
            iLoop++;
        }

        ListNode* start = nullptr;
        if (dummy->next != nullptr) start = dummy->next;
        delete dummy;

        ListNode* result = ReverseList(start);
        return result;
    }
};
