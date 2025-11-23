class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int>remind1 ,remind2;
        for(int num : nums){
            sum+=num;
            if(num % 3 == 1){
                remind1.push_back(num);
            }
            if(num % 3 ==2){
                remind2.push_back(num);
            }
        }
        if(sum % 3 ==0){
            return sum;
        }
        int reminder=sum%3;
        sort(remind1.begin(),remind1.end());
        sort(remind2.begin(),remind2.end());
        
        int res=0;

        if(reminder==1){
            int remove1=(remind1.size() >= 1) ? remind1[0] : INT_MAX;
            int remove2=(remind2.size() >=2) ? remind2[0]+remind2[1] : INT_MAX;
            res=sum-min(remove1 ,remove2);
        }
        if(reminder==2){
            int remove1=(remind2.size() >= 1) ? remind2[0] : INT_MAX;
            int remove2=(remind1.size() >=2) ? remind1[0]+remind1[1] : INT_MAX;
            res=sum-min(remove1 ,remove2);
        }
        return (res==INT_MAX) ? 0: res;
    }
};