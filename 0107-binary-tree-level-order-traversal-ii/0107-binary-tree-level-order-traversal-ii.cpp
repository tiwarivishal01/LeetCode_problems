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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // dont fall for complex solution think in way make a normal level order traversal and then reversing the ans before return consider the tree in 1 eg: level Order :- [[3][9,20],[15,7]] ----> make it [[15,7],[9,20],[3]]

        vector<vector<int>>ans;
        queue<TreeNode*>q;
        //check base case
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode* nod = q.front();
                q.pop();
                temp.push_back(nod->val);
                if(nod->left) q.push(nod->left);
                if(nod->right) q.push(nod->right);

            }
            ans.push_back(temp);
           
        }
         reverse(ans.begin(),ans.end());
        return ans;
        
    }
};