class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        int remove_idx=0;
        while(arr.size()>1){
            remove_idx=(remove_idx + k-1) % arr.size();
            arr.erase(arr.begin()+remove_idx);
        }
        return arr[0];
    }
};