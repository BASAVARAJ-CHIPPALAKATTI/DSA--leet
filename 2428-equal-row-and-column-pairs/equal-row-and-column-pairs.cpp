//store all rows in map wiht freq
// go all col check how many rows are equal and in to the result
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        map<vector<int>,int>mp;
        //store row in to map
        for(int row=0;row<n;row++){
            mp[grid[row]]++;
        }
        for(int c=0;c<n;c++){
            vector<int>temp;
            for(int r=0;r<n;r++){
                temp.push_back(grid[r][c]);
            }
            count+=mp[temp];
        }
        return count;
    }
};