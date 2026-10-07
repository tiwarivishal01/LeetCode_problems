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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int lev = q.size();
            for(int i=0;i<lev;i++){
                TreeNode* Node = q.front();
                q.pop();
                if(Node->left != nullptr){
                    q.push(Node->left);
                }
                if(Node->right != nullptr){
                    q.push(Node->right);
                }
            }
            depth++;

        }
        return depth;
        
    }
};