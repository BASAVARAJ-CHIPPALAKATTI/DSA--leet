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
    int maxLevelSum(TreeNode* root) {
        int level=1;
        int sumval=root->val;
        queue<TreeNode*>q;
        q.push(root);
        int currlevel=0;
        while(!q.empty()){
            int n=q.size();
            int currsum=0;
            currlevel++;
            while(n--){
                TreeNode*temp=q.front();
                q.pop();
                currsum+=temp->val;
                if(temp->right){ q.push(temp->right); }
                if(temp->left){ q.push(temp->left); }
            }
            if(currsum>sumval){
                sumval=currsum;
                level=currlevel;
            }
        }
        return level;
    }
};