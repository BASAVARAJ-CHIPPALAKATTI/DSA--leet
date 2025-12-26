class Solution {
public:
    int t[100001][2];
    int minFlipsMonoIncr(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,0);
    }
    int solve(string &s,int idx,int prev_val){
        if(idx >= s.size()){
            return 0;
        }
        //we have two option
        if(t[idx][prev_val]!=-1){
            return t[idx][prev_val];
        }
        int flip=INT_MAX;
        int not_flip=INT_MAX;
        if(s[idx]=='0'){
            if(prev_val==0){
                flip =1+solve(s,idx+1,1);
                not_flip=solve(s,idx+1,0);
            }
            else{ //prev_val==1
                flip =1+solve(s,idx+1,1); //if prev_val 1 we need to continue ans 1 only
            }
        }
        else{  //curr =1
            if(prev_val ==0){
                flip =1+solve(s,idx+1,0);
                not_flip=solve(s,idx+1,1);
            }
            else{  //prev_val=1
                not_flip=solve(s,idx+1,1);
            }
        }
        return t[idx][prev_val]=min(flip,not_flip);
    }

};