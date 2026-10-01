/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        std::unordered_map<Node*, Node*> clones;
        std::queue<Node*> qOriginalNode;
        
        Node* resultClone = new Node(node->val);
        clones.insert({node, resultClone});
        qOriginalNode.push(node);

        while (qOriginalNode.empty() != true) {
            Node* current = qOriginalNode.front();
            qOriginalNode.pop();

            Node* currentClone = clones.at(current);
            for (Node* neighbor : current->neighbors) 
            {
                Node* nbrClone = nullptr;
                if (clones.find(neighbor) == clones.end()) 
                {
                    nbrClone = new Node(neighbor->val);
                    clones.insert({neighbor, nbrClone});
                    qOriginalNode.push(neighbor);
                } 
                else 
                {
                    nbrClone = clones.at(neighbor);
                }
                currentClone->neighbors.push_back(nbrClone);
            }
        }

        return resultClone;
    }
};
