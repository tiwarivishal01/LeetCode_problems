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
    TreeNode* start;
    bool find(TreeNode* node, TreeNode* Snode) {
        if (!node || !Snode)
            return false;
        if (checkSymetric(node, Snode))
            return true;
        return find(node->left, Snode) || find(node->right, Snode);
    }
    bool checkSymetric(TreeNode* start, TreeNode* subRoot) {
        // check if both are null
        if (!start && !subRoot)
            return true;
        if (!start || !subRoot)
            return false;
        // if values are equal or not
        if (start->val != subRoot->val) {
            return false;
        }
        return checkSymetric(start->left, subRoot->left) &&
               checkSymetric(start->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return find(root, subRoot);
    }
};