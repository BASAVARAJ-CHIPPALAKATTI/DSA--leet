class Solution {
public:
//medium level
    double epislon = 1e-6;;
    bool solve(vector<double>& nums){
        if(nums.size()==1){  //3/8 * 3 == 8(7.999999)
            if(abs(nums[0]-24.0) <=epislon){
                return true;
            } 
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j){
                    continue;
                }
                vector<double>temp;
                for(int k=0;k<nums.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(nums[k]);
                    }
                }
                double a=nums[i];
                double b=nums[j];
                vector<double>all_oper={a+b,a-b,b-a,a*b};
                if(a!=0.0){
                    all_oper.push_back(b/a);
                }
                if(b!=0.0){
                    all_oper.push_back(a/b);
                }

                for(double num : all_oper){
                    temp.push_back(num);
                    if(solve(temp)==true){
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;  //not get 24
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(int i=0;i<4;i++){
            nums.push_back(cards[i] * (1.0));
        }
        return solve(nums);
    }
    
};