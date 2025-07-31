class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev,curr,ans;
        for(int i=0;i<arr.size();i++){  //O(n)
            for(int x: prev){  // max of 32 bit
                curr.insert(x|arr[i]);
                ans.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);

            prev=curr;
            curr.clear();
        }
        return ans.size();
    }
};