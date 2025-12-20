//easy
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if(tasks.size() ==1){
            return -1;
        }
        sort(tasks.begin(),tasks.end());
        int count=1;
        int res=0;
        for(int i=1;i<tasks.size();i++){
            if(tasks[i-1]==tasks[i]){
                count++;
            }
            else{
                if(count==1){
                    return -1;
                }
                res+=count/3;
                if(count%3 !=0){
                    res++;
                }
                count=1;

            }
        }
        if(count==1){
            return -1;
        }
        res+=count/3;
        if(count%3 !=0){
            res++;
        }
        return res;
    }
};