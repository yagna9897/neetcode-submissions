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
ListNode* findMidNode(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    return prev;
}

ListNode* ReverseListNode(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr)
    {
        ListNode* next1 = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next1;
    }

    return prev;
}

ListNode* MergeLists(ListNode* head1, ListNode* head2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;

    int loop = 1;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (loop % 2 != 0)
        {
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
        
        loop++;
    }

    if (head1 != nullptr)
        curr->next = head1;
    if (head2 != nullptr)
        curr->next = head2;
    return dummy->next;
}

    void reorderList(ListNode* head) {
    if (head->next == nullptr) return;
    ListNode* Node = findMidNode(head);
    ListNode* midNode = nullptr;
        midNode = Node->next;
    Node->next = nullptr;
    ListNode* RevNode = ReverseListNode(midNode);
    ListNode* ReorderNode = MergeLists(head, RevNode);
    }
};
