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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        if(!root) return vec;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int lev = qu.size();
            vector<int>tem;
            //process teh lev;
            for(int i=0;i<lev;i++){
                TreeNode* node = qu.front();
                tem.push_back(node->val);
                qu.pop();
                //check if left and rigt are not null
                if(node->left != nullptr){
                    qu.push(node->left);
                }
                if(node->right != nullptr){
                    qu.push(node->right);
                }
                
            }
            vec.push_back(tem);

        }
        return vec;
        
    }
};