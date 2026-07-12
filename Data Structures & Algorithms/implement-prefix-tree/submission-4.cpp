class TrieNode{
public:
    TrieNode* children[26];
    bool bIsEnd{false};
    TrieNode(){
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        bIsEnd = false;
    }
};
class PrefixTree {
    private: 
    TrieNode* root;
public:
    PrefixTree() {
            root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if(current->children[index] == nullptr)
                current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->bIsEnd = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for(int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if(current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        if(current->bIsEnd == false)
            return false;
        else
            return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
