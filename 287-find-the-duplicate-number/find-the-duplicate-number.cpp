class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while (true) {
            int next = abs(nums[i]);
            if (nums[next] < 0) {
                return next;
            }
            nums[next] = -nums[next];
            i = next;
        }
    }
};