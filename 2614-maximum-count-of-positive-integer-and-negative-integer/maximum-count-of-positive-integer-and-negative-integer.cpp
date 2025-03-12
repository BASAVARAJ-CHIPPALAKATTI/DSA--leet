class Solution {
public:

    int maximumCount(vector<int>& nums) {

        // // using STL count_it  O(n)

        // auto countitp=[](int num){
        //     return num>0;
        // };
        // auto countitn=[](int num){
        //     return num<0;
        // };
        // int postive=count_if(nums.begin(),nums.end(),countitp);
        // int negtive=count_if(nums.begin(),nums.end(),countitn);

        // return max(postive,negtive);

        // using lower bound O(log(n))
        int n=nums.size();
        int Pidx=lower_bound(nums.begin(),nums.end(),1)-nums.begin(); // passing 1 checks >=1 
        // -nums.begin() because return idx otherwise it returns number
        int Nidx=lower_bound(nums.begin(),nums.end(),0)-nums.begin();

        return max(n-Pidx,Nidx);
    }
};