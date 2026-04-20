class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        int n=status.size();
        unordered_set<int>havebox;
        vector<bool>visited(n,false);

        for(int box : initialBoxes){
            havebox.insert(box);
            if(status[box]){
                q.push(box);
                visited[box]=true;
            }
        }

        int candy=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int curr=q.front();
                q.pop();
                
                candy+=candies[curr]; 

                for(int box : containedBoxes[curr]){
                    havebox.insert(box);
                    if(status[box] && !visited[box]){
                        q.push(box);
                        visited[box]=true;
                    }
                }
                for(int k: keys[curr]){
                    status[k]=1; // if future comes
                    //else alredy there box
                    if(!visited[k] && havebox.count(k)){
                        q.push(k);
                        visited[k]=true;
                    }

                }
            }
        }
        return candy;
    }
};