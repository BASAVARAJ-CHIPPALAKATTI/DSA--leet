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
// Great question! You're asking why we do path.pop_back() to backtrack, but we don't undo targetSum -= root->val by doing targetSum += root->val.

// Here's the key reason:
// In your DFS function, targetSum is passed by value, not by reference. So when you do:

// cpp
// Copy
// Edit
// targetSum -= root->val;
// …it only affects the local copy of targetSum for that call of the function. The original value remains unchanged for the caller. That's why you don't need to do targetSum += root->val during backtracking.

// In contrast:
// cpp
// Copy
// Edit
// vector<int>& path
// This is passed by reference, so changes to path in the function do affect the original vector, and hence:

// You do path.push_back(...) to add to the path.

// And path.pop_back() to undo that change during backtracking.