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
    bool solve(TreeNode* node, int sum, int targetsum){
        if(!node) return false;
        int currSum = sum + node->val;
        if(!node->left && !node->right){
            return currSum == targetsum;
        }
        return solve(node->left, currSum, targetsum) || solve(node->right, currSum, targetsum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
      return solve(root,0,targetSum);
    }
};