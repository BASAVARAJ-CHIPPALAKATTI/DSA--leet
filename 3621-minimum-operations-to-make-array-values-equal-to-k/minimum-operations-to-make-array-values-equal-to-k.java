class Solution {
    public int minOperations(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<>();
        int n = nums.length;
        for(int i =0;i<n;i++){
           if(nums[i] <k){
            return -1;//if not able to convert it to the k 
           }
           else if(nums[i] >k){
            set.add(nums[i]);
           }
        }
        return set.size();
    }
}