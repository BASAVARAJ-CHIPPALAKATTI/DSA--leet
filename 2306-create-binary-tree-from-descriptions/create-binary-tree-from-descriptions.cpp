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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>rootone;  //help us to return root;
        for(int i=0;i<descriptions.size();i++){
            int par=descriptions[i][0];
            int chi=descriptions[i][1];
            int left=descriptions[i][2];
            if(mp.find(par)==mp.end()){
                mp[par]=new TreeNode(par);
            }
            if(mp.find(chi)==mp.end()){
                mp[chi]=new TreeNode(chi);
            }
            if(left){
                mp[par]->left=mp[chi];
            }
            else{
                mp[par]->right=mp[chi];
            }
            if(!rootone.count(chi)){
                rootone.insert(chi);
            }
        }
        for(int i=0;i<descriptions.size();i++){
            if(!rootone.count(descriptions[i][0])){
                return mp[descriptions[i][0]];
            }
        }
        return mp[descriptions[0][0]];
    }
};