// sorting , taking one number(x) and we find two numbers (y,z) using two
// pointers thai equal to -x
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) { // to avoid duplicates
                continue;
            }
            int target = -(nums[i]);
            twosum(nums, target, i + 1, n - 1);
        }
        return result;
    }
    void twosum(vector<int> nums, int target, int i, int j) {
        while (i < j) {
            if (nums[i] + nums[j] > target) {
                j--;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                while (i < j && nums[i] == nums[i + 1]) { // to avoid duplicates
                    i++;
                }
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }
};