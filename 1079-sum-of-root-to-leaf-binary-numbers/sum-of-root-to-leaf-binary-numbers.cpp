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
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
    int solve(TreeNode* root,int currans){
        if(!root){
            return 0;
        }
        currans= (currans << 1)|root->val;
        if(!root->left  && !root->right){
            return currans;
        }
        int left=solve(root->left,currans);
        int right=solve(root->right,currans);

        return right+left;
    }
};