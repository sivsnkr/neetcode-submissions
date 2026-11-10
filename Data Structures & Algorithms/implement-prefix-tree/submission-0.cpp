class PrefixTree {
    struct Node {
        vector<Node*> childs;
        bool end;

        Node() {
            childs = vector<Node*>(26, NULL);
            end = false;
        }
    };
    Node* head;
public:
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
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
        Node* ch = head;
        for(char c : word) {
            if(ch->childs[c - 'a'] == NULL) {
                return false;
            }
            ch = ch->childs[c - 'a'];
        }
        return ch->end;
    }
    
    bool startsWith(string prefix) {
        Node* ch = head;
        for(char c : prefix) {
            if(ch->childs[c - 'a'] == NULL) {
                return false;
            }
            ch = ch->childs[c - 'a'];
        }
        return true;
    }
};
