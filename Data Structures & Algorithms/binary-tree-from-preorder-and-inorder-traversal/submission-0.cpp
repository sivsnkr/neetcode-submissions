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

class Solution {
    TreeNode* build(int l, int r, int &cur, vector<int> &preorder, vector<int> &inorder) {
        if(l > r || cur == preorder.size()) return NULL;

        TreeNode* currNode = new TreeNode(preorder[cur]);
        cur++;
        int mid;

        for(int i = l; i <= r; i++) {
            if(inorder[i] == currNode->val) {
                mid = i;
                break;
            }
        }

        currNode->left = build(l, mid - 1, cur, preorder, inorder);
        currNode->right = build(mid + 1, r, cur, preorder, inorder);

        return currNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cur = 0;
        return build(0, inorder.size() - 1, cur, preorder, inorder);
    }
};
