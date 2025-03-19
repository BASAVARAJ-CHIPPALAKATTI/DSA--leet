// just do what they telled
class Solution {
public:
    int count = 0;
    // do the xor of 1 and nums[i]
    // 0 become 1
    // 1 become 0
    int minOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                if (i + 2 < nums.size()) {
                    nums[i] ^= 1;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                } else {
                    return -1;
                }
            }
        }
        return count;
    }
};