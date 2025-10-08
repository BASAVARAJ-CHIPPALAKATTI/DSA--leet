class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;

        sort(potions.begin(),potions.end());

        for(int i=0;i<spells.size();i++){
            long long val = ceil((1.0 * success) / spells[i]);
            int it=lower_bound(potions.begin(),potions.end(),val)-potions.begin();
            ans.push_back(potions.size()-it);
        }
        return ans;
    }
};