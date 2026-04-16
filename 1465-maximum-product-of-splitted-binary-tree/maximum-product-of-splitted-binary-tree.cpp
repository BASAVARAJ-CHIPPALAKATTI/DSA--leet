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
    int M=1e9+7;
    long total_sum=0;
    long ans=INT_MIN;

    int maxProduct(TreeNode* root) {
        total_sum=find_total_sum(root);
        find_sum_pro(root);
        return ans%M;
    }
    long find_total_sum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val+find_total_sum(root->left)+find_total_sum(root->right);
    }
    int find_sum_pro(TreeNode* root){
        if(!root){
            return 0;
        }
        long left=find_sum_pro(root->left);
        long right=find_sum_pro(root->right);
        long currans=root->val+left+right;

        ans=max(ans,(currans*(total_sum-currans)));
        return currans;
    }
};