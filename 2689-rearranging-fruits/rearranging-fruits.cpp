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
/*
1. Frequency Difference Mapping:
Use an unordered_map to count the net frequency of each item by incrementing for basket1 and decrementing for basket2. If any item has an odd count, it's impossible to equalize the baskets, so return -1.

2. Track Minimum Value:
While traversing both baskets, track the global minimum value (minval) to potentially use it as a cheap swap cost (twice the minimum can be cheaper than direct swap).

3. Extract Extra Items for Swapping:
For every value whose frequency difference is non-zero (but even), push half the absolute difference into an array extra_val to prepare for swapping.

4. Cost Minimization Using Sorting:
Sort the extra_val array and, for the first half (i.e., smallest required swaps), compute the cost using either the value itself or 2 * minval, whichever is smaller — ensuring minimal total swap cost.
*/