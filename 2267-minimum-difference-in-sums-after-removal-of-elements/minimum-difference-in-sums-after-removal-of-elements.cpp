class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;
        vector<long long>left_min_sum(N,0);
        vector<long long>right_max_sum(N,0);
        long long cummsum=0;
        priority_queue<int>max_heap; 
        for(int i=0;i<2*n;i++){
            cummsum+=nums[i];
            max_heap.push(nums[i]);
            if(max_heap.size() > n){
                cummsum-=max_heap.top();
                max_heap.pop();
            }
            left_min_sum[i]=cummsum;
        }
        cummsum=0;
        priority_queue<int,vector<int> ,greater<int>>min_heap;
        for(int i=N-1;i>=n;i--){
            cummsum+=nums[i];
            min_heap.push(nums[i]);
            if(min_heap.size() >n){
                cummsum-=min_heap.top();
                min_heap.pop();
            }
            right_max_sum[i]=cummsum;
        }
        long long res=LLONG_MAX;
        for(int i=n-1;i<2*n;i++){
            res=min(res,(left_min_sum[i]-right_max_sum[i+1]));
        } 
        return res;
    }
};