class Solution {
    public int subarraySum(int[] nums, int k) {
        
        int n = nums.length;
        int pref[] = new int[n];
        pref[0] = nums[0];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }
        int count = 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        for(int i = 0;i<n;i++){
            int diff = pref[i] - k;
            if(map.containsKey(diff)){
                count+=map.get(diff);
            }
            map.put(pref[i],map.getOrDefault(pref[i],0)+1);
        }
        return count;
    }
}