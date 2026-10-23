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
    int cnt(TreeNode* root, int curMax) {
        if(root == NULL) return 0;

        int res = 0;
        if(root->val >= curMax) res++;
        int nextMax = max(curMax, root->val);

        res += cnt(root->left, nextMax);
        res += cnt(root->right, nextMax);

        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return cnt(root, INT_MIN);
    }
};
