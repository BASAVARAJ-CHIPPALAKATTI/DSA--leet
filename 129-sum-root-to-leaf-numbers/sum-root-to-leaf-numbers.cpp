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
    int ans=0;
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
    void solve(TreeNode* root,int currsum){
        if(!root){
            return ;
        }
        currsum=currsum*10+root->val;
        if(!root->left && !root->right){
            ans+=currsum;
        }
        solve(root->left,currsum);
        solve(root->right,currsum);
    }
};