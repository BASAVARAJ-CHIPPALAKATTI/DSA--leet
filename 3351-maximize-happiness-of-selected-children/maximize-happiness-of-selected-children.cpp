class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        int count=0;
        for(int i=0;i<happiness.size();i++){
            if(happiness[i]-count <=0 || k <=0){
                break;
            }
            ans+=happiness[i]-count;
            count++;
            k--;
        }
        return ans;
    }
};