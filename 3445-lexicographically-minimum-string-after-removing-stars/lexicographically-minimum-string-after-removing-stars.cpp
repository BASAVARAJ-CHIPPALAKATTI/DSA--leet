//own
class Solution {
public:
    typedef pair<char,int> P;
    struct comp{
        bool operator()(P &p1, P&p2){
            if(p1.first==p2.first){
                return(p1.second<p2.second);
            }
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        int n=s.size();
        priority_queue<P,vector<P>,comp >min_heap;  //one extrat thing we need to do is make our own comp for if char is equal than greater int should be 1st prior 
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                s[min_heap.top().second]='*';
                min_heap.pop();
            }
            else{
                min_heap.push({s[i],i});
            }
        }
    
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};