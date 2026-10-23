/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
    string padstring(TreeNode* root) {
        if(root == NULL) {
            return string(5, '#');
        }

        if(root->val >= 0) {
            string value = to_string(root->val);
            if(value.length() < 5) {
                return string(5 - value.length(), '0') + value;
            }
            return value;
        }

        root->val = abs(root->val);
        string result = padstring(root);
        root->val = -root->val;
        return string(1, '-') + result;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> st;
        st.emplace(root);
        string res = "";

        while(!st.empty()) {
            int sz = st.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* rt = st.front();
                st.pop();
                res += padstring(rt);
                if(rt) {
                    st.emplace(rt->left);
                    st.emplace(rt->right);
                }
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#') return NULL;

        queue<TreeNode*> st;

        int rootvalue = stoi(data.substr(0, 5));
        TreeNode* root = new TreeNode(rootvalue);
        st.emplace(root);
        int curi = 5;

        while(!st.empty()) {
            int sz = st.size();
            for(int i = 0; i < sz && curi < data.length(); i++) {
                TreeNode* root = st.front();
                st.pop();

                string lc = data.substr(curi, 5);
                curi += 5;
                if(lc[0] != '#') {
                    root->left = new TreeNode(stoi(lc));
                    st.emplace(root->left);
                }

                if(curi < data.length()) {
                    string rc = data.substr(curi, 5);
                    curi += 5;
                    if(rc[0] != '#') {
                        root->right = new TreeNode(stoi(rc));
                        st.emplace(root->right);
                    }
                }
            }
        }

        return root;
    }
};
