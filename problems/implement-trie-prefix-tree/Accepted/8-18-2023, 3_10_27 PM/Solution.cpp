// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:

    struct Node {
        struct Node* child[26];
        bool isend = false;
    };

    Node* root;

    Node* getNode() {
        Node* n = new Node();
        
        for (int i = 0; i < 26; i++) {
            n->child[i] = NULL;
        }

        return n;
    }

    Trie() {
        this->root = getNode();
    };
    
    void insert(string word) {
        
        Node* it = this->root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!it->child[index]) it->child[index] = getNode();
            it = it->child[index];
        }
        
        it->isend = true;
    }
    
    bool search(string word) {
        Node* it = this->root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!it->child[index]) return false;
            it = it->child[index];
        }

        return it->isend;
    }
    
    bool startsWith(string prefix) {
        Node* it = this->root;

        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (!it->child[index]) return false;
            it = it->child[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */