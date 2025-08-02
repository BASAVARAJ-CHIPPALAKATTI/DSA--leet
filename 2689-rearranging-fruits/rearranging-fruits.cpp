class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>freq_mp;
        int minval=INT_MAX;

        for(int &val : basket1){
            freq_mp[val]++;
            minval=min(minval,val);
        }
        for(int &val : basket2){
            freq_mp[val]--;
            minval=min(minval,val);
        }
        vector<int>extra_val;
        for(auto x : freq_mp){
            int val=x.first;
            int count=x.second;

            if(count%2!=0){
                return -1;
            }
            for(int i=1;i<=abs(count)/2;i++){  //we need replace half 
                extra_val.push_back(val);
            }
        }
        long long ans=0;
        sort(extra_val.begin(),extra_val.end());

        for(int i=0;i<extra_val.size()/2;i++){
            ans+=min(extra_val[i], minval*2);

        }
        return ans;
    }
};