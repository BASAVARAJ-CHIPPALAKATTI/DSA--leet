class Solution(object):
    def twoSum(self, nums, target):
        mp={}
        for i in range(len(nums)):
            mp[nums[i]]=i

        for i in range(len(nums)):
            val=target-nums[i]
            if val in mp and mp[val]!=i:
                return [i,mp[val]]
            
        return []
        