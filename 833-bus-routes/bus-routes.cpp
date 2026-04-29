class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(int val : routes[i]){
                mp[val].push_back(i);
            }
        }
        queue<int>q;
        vector<bool>visited(routes.size(),false);
        for(int val : mp[source]){
            q.push(val);
            visited[val]=true;
        } 
        int total_bus=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){

               int route=q.front();
               q.pop();

               for(int val : routes[route]){
                   if(val==target){
                    return total_bus;
                   }
                   for(int i : mp[val]){
                       if(!visited[i]){
                        q.push(i);
                        visited[i]=true;
                       }
                   }
               }
                
            }
            total_bus++;
        }
        return -1;
    }
};