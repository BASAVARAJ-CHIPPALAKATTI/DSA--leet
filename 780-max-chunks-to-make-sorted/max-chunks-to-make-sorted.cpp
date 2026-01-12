class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxelt=-1;
        int chunk=0;
        for(int i=0;i<arr.size();i++){
            maxelt=max(maxelt,arr[i]);
            if(i==maxelt){
                chunk++;
            }
        }
        return chunk;
    }
};