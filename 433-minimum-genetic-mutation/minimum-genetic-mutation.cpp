class Solution {
public:
    // every time try to replace letter with AGCT
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>Bank(bank.begin(),bank.end());
        unordered_set<string>visited;
        int  level=0;
        queue<string>q;
        q.push(startGene);
        while(!q.empty()){
            int n=q.size();
            
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endGene) {
                    return level; //taking time
                }
                visited.insert(curr);
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char c : "AGCT"){  // TRY TO REPLACE WITH AGCT
                        temp[i]=c;
                        if(!visited.count(temp) && Bank.count(temp)){
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};