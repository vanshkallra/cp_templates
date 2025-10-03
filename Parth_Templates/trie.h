class TrieNode {
public:
    vector<TrieNode*> child;
    bool endPoint;
    TrieNode () {
        child.resize(26, NULL);
        endPoint = false;
    }
};

class trie {
public:
    TrieNode* root;
    trie () {
        root = new TrieNode();
    }
    void add(string word) {
        insert(root, 0, word);
    }
    void insert (TrieNode* root, int ind, string& word) {
        if (ind == word.length()) {
            root->endPoint = true;
            return;
        }
        char ch = word[ind];
        TrieNode* next = NULL;
        if (root->child[ch - 'a'] != NULL) {
            next = root->child[ch - 'a'];
        }
        else {
            next = new TrieNode();
        }
        root->child[ch - 'a'] = next;
        insert(next, ind + 1, word);
    }
};