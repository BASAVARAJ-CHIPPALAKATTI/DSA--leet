//revision
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int>mp;
        set<int>st;  //store the zero rian index

        vector<int>ans(n,1);
        for(int i=0;i<rains.size();i++){
            int rain=rains[i];

            if(rain==0){ 
                st.insert(i);
            }
            else{
                ans[i]=-1;
                if(mp.count(rain)){//if alredy exist flood comes
                    auto it=st.upper_bound(mp[rain]);

                    if(it==st.end()){
                        //flood comes
                        return {};
                    }
                    else{
                        ans[*it]=rain;
                        st.erase(it);
                    }
                }
                mp[rain]=i;
            }
        }
        return ans;
    }
};