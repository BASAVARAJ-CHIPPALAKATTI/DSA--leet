class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>res;
        for(int num : nums){
            while(!res.empty()){
                int prev=res.back();
                int GCD=gcd(prev,num);
                if(GCD==1){
                    break;  //we need to push_back in res
                }
                //if gcd is not 1 than we need pop_back arr last elt
                res.pop_back();
                int lcm=prev/GCD*num;
                num=lcm;
            }
            res.push_back(num);
        }
        return res;
    }
};