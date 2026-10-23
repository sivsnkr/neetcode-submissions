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
    int rec(TreeNode* root, int &res) {
        if(root == NULL) return 0;

        int sl = rec(root->left, res);
        int sr = rec(root->right, res);

        int val = sl + sr + root->val;
        res = max(res, val);

        return max(0, max(sl, sr) + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        rec(root, res);
        return res;
    }
};
