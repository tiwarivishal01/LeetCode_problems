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
    bool check(TreeNode* Sleft, TreeNode* Sright) {
        if (!Sleft && !Sright)
            return true;

        if (!Sleft || !Sright)
            return false;

        if (Sleft->val != Sright->val)
            return false;

        return check(Sleft->left, Sright->right) &&
               check(Sleft->right, Sright->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return check(root->left, root->right);
    }
};