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
    void rec(TreeNode* root, int &k, int &res) {
        if(root == NULL || k == 0) return;
        rec(root->left, k, res);
        if(k == 1) {
            res = root->val;
        }
        k--;
        rec(root->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        rec(root, k, res);
        return res;
    }
};
