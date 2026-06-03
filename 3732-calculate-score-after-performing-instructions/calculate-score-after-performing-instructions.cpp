class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n=instructions.size();
        vector<bool>visited(n,false);
        int i=0;
        long long score=0;
        while(i < n && i>=0){
            if(visited[i]==true){
                return score;
            }
            else{
                visited[i]=true;
            }
            if(instructions[i]=="jump"){
                i=i+values[i];
            }
            else{
                score=score+values[i];
                i++;
            }
        }
        return score;
    }
};