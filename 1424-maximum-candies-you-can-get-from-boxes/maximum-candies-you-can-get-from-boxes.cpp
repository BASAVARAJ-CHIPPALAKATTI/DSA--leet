//do what they told by dfs
//revision
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int totalcandies=0;
        unordered_set<int>visited;
        unordered_set<int>foundedbox;
        for(int box : initialBoxes){
            totalcandies+=dfs(box,status,candies, keys,containedBoxes,visited,foundedbox);
        }
        return totalcandies;
    }
    int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,unordered_set<int>&visited,unordered_set<int>&foundedbox){
        if(visited.count(box)){
            return 0;
        }
        if(status[box]==0){
            //but we need to insert
            foundedbox.insert(box);
            return 0;
        }
        visited.insert(box);
        int totalcandies=candies[box];
        for(int containbox :containedBoxes[box]){
            totalcandies+=dfs(containbox,status,candies, keys,containedBoxes,visited,foundedbox);
        }
        for(int keybox:keys[box]){
            status[keybox]=1;
            if(foundedbox.count(keybox)){
                totalcandies+=dfs(keybox,status,candies, keys,containedBoxes,visited,foundedbox);
            }
        }
        return totalcandies;
    }
};