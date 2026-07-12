class TrieNode {
   public:
    TrieNode* children[26];
    bool bIsEnd{false};
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class WordDictionary {
   private:
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (node == nullptr) return false;

        if (index == word.length()) return node->bIsEnd;

        if (word[index] != '.') {
            int idx = word[index] - 'a';
            if (dfs(node->children[idx], word, index + 1)) return true;
        } else {
            for (int idx = 0; idx < 26; idx++) {
                if (node->children[idx] != nullptr) {
                    if (dfs(node->children[idx], word, index + 1)) return true;
                }
            }
        }

        return false;
    }

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (auto c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->bIsEnd = true;
    }
    bool search(string word) { return dfs(root, word, 0); }
};
