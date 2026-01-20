class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>nu1,nu2;
        for(int num : nums1){
            nu1[num]++;
        }
        for(int num : nums2){
            nu2[num]++;
        }
        for(auto &it : nu1){
            if(nu2.count(it.first)){
                for(int i=0;i<min(nu1[it.first],nu2[it.first]) ;i++){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};