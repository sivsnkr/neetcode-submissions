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
    Node* rec(Node* root, unordered_map<int, Node*> &mp) {
        if(root == NULL) return NULL;
        auto it = mp.find(root->val);
        if(it != mp.end()) return it->second;

        Node* res = new Node(root->val);
        mp[root->val] = res;

        for(Node* child : root->neighbors) {
            res->neighbors.emplace_back(rec(child, mp));
        }

        return res;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        return rec(node, mp);
    }
};
