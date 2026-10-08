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
public:
    int daimeter;
    int height(TreeNode* node){
        if(!node) return -1;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        daimeter = max(daimeter, leftHeight+rightHeight+2);
        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return daimeter;
        
    }
};