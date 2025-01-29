class Solution {
    //time complexity is O(n)
    //create a graph
    //no need to take the visited array because tree doesnot contains the cycle 
    //and need to track the parent because this is undirected graph so 0 to 1 and then 1 to 0 (to avoid second case)
    public int DFS( ArrayList<ArrayList<Integer>> adj,int curr,int parent,List<Boolean> hasApple){
        int time = 0;
        for(int child : adj.get(curr)){
            //if the child is parent then continue
            if(child == parent) continue;
            int time_from_the_child = DFS(adj,child,curr,hasApple);
            //if the child give the time or child has the apple then add the time ---------> important
            if(time_from_the_child>0 || hasApple.get(child) == true){
                time+=time_from_the_child +2;
            }
        }
        return time;
    }
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for(int i =0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        //1. create the graph
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        return DFS(adj,0,-1,hasApple);
    }
}