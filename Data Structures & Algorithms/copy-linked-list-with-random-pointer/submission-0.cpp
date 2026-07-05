/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* newNode = new Node(head->val);
        Node* newHead = newNode;

        unordered_map<Node*, Node*> hm;
        hm.insert({head, newNode});
        Node* oldNode = head->next;
        while (oldNode != nullptr) {
            newNode->next = new Node(oldNode->val);
            hm.insert({oldNode, newNode->next});

            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        oldNode = head;
        newNode = newHead;
        while (oldNode != nullptr) {
            auto it = hm.find(oldNode->random);

            if (it != hm.end()) newNode->random = it->second;

            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};
