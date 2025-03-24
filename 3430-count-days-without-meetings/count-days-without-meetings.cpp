
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int avail=0;
        sort(meetings.begin(),meetings.end());

        int st=0;
        int end=0;
        for(int i=0;i<meetings.size();i++){
            if( meetings[i][0]> end){
                avail+=meetings[i][0]-end-1;
            }
            end=max(end,meetings[i][1]); // due to overlap
        }
       // if(days> end){
            avail+=days-end;  // for last one
        //}
        return avail;
    }
};