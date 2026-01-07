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
    long totalSum=0;
    long maxprod=0;
    int M=1e9+7;
    int maxProduct(TreeNode* root) {
        totalSum=sumfind(root);
        maxpro(root);
        return maxprod % M;
    }
    long sumfind(TreeNode* root) {
        if (!root) return 0;
        return root->val + sumfind(root->left) + sumfind(root->right);
    }

    long maxpro(TreeNode* root){
        if(!root){
            return 0;
        }
        long leftsum=maxpro(root->left);
        long rightsum=maxpro(root->right);
        long currsum= root->val + leftsum +rightsum;

        maxprod=max(maxprod,currsum*(totalSum-currsum));
        return currsum;
    }
};