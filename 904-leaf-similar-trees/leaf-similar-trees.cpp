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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";
        collectval(root1,s1);
        collectval(root2,s2);
        return (s1==s2);
    }
    void collectval(TreeNode* root,string &s){
        if(!root) return ;
        if(!root->left && !root->right){
            s+=to_string(root->val)+ " ";
            return ;
        }
        collectval(root->left,s);
        collectval(root->right,s);
    }
};