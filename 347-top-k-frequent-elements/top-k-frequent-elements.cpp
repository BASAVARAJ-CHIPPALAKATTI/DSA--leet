class Solution {
public: 
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num: nums){
            freq[num]++;
        }
        priority_queue<p>max_heap;
        for(auto &it: freq){
            max_heap.push({it.second,it.first});
        }
        vector<int>ans;
        while(k){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
            k--;
        }
        return ans;
    }
};