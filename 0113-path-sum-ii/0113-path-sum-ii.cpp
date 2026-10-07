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
    vector<vector<int>> solve(TreeNode* node, int sum, int targetSum, vector<int>& path, vector<vector<int>>& ans){
        if(!node) return ans;
        int currSum = sum + node->val;
        path.push_back(node->val);
        //check for the ans and push back the ans if val8d
        if(!node->left && !node->right){
             if(currSum == targetSum){
                ans.push_back(path);
             }
        }
        // Explore children
        solve(node->left, currSum, targetSum, path, ans);
        solve(node->right, currSum, targetSum, path, ans);

        // Backtrack
        path.pop_back();
        return ans;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, 0 , targetSum, path, ans);
        return ans;
    }
};