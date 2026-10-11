/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool checkValid(TreeNode* node, long long minVal, long long maxVal) {
        if (!node)
            return true;
        // check if node val is in allowed range and if not simply return false
        // so that not habe to check in all postive cond can check and pass on
        // neg ones
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        // update the range

        // check for left
        return checkValid(node->left, minVal, node->val) &&
               checkValid(node->right, node->val, maxVal);
    }
    bool isValidBST(TreeNode* root) { return checkValid(root, LLONG_MIN, LLONG_MAX); }
};