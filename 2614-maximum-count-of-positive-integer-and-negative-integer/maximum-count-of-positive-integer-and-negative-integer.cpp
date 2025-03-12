class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto countitp=[](int num){
            return num>0;
        };
        auto countitn=[](int num){
            return num<0;
        };
        int postive=count_if(nums.begin(),nums.end(),countitp);
        int negtive=count_if(nums.begin(),nums.end(),countitn);

        return max(postive,negtive);
    }
};