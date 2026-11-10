class WordDictionary {
    struct Node {
        vector<Node*> childs;
        bool end;

        Node() {
            childs = vector<Node*>(26, NULL);
            end = false;
        }
    };
    Node* head;
    bool rec(string &word, int i, Node* cur) {
        if(word.length() - 1 == i) {
            if(word[i] == '.') {
                for(int it = 0; it < 26; it++) {
                    if(cur->childs[it] != NULL && cur->childs[it]->end) return true;
                }
                return false;
            }
            cur = cur->childs[word[i] - 'a'];
            if(cur != NULL && cur->end) return true;
            return false;
        }

        if(word[i] != '.') {
            if(cur->childs[word[i] - 'a'] != NULL) {
                return rec(word, i + 1, cur->childs[word[i] - 'a']);
            }
            return false;
        }
        for(int it = 0; it < 26; it++) {
            if(cur->childs[it] != NULL && rec(word, i + 1, cur->childs[it])) {
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node* ch = head;
        for(char c : word) {
            if(ch->childs[c - 'a'] == NULL) {
                ch->childs[c - 'a'] = new Node();
            }
            ch = ch->childs[c - 'a'];
        }
        ch->end = true;
    }
    
    bool search(string word) {
        return rec(word, 0, head);
    }
};
