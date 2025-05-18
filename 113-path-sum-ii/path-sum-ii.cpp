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
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>currans;
        solve(root,targetSum,currans);
        return ans;
    }
    void solve(TreeNode* root,int targetSum,vector<int>&currans){
        if(!root){
            return ;
        }
        currans.push_back(root->val);
        targetSum-=root->val;
        if(!root->right && !root->left){
           if(targetSum==0){
            ans.push_back(currans);
           }
        }
        else{
            solve(root->left,targetSum,currans);
            solve(root->right,targetSum,currans);
        }
        currans.pop_back();
    }
};