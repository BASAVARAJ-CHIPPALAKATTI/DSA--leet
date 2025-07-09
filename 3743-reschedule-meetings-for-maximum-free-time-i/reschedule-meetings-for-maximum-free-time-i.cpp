class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freetime;
        //store the freeTime
        freetime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freetime.push_back(startTime[i]-endTime[i-1]);
        }
        freetime.push_back(eventTime-endTime[endTime.size()-1]);

        //sliding window
        int i=0;
        int j=0;
        int totalsum=0;
        int currsum=0;
        while(j<freetime.size()){
            currsum+=freetime[j];
            if(j-i+1 > k+1){
                currsum-=freetime[i];
                i++;
            }
            totalsum=max(totalsum,currsum);
            j++;
        }
        return totalsum;
    }
};