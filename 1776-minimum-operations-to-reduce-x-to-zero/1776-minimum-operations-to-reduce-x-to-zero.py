class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        maxlen = -1
        presum = l = 0
        arrsum = sum(nums)
        target = arrsum - x
        if(target < 0):
            return -1
        for r in range(0, len(nums)):
            presum += nums[r]
            while(presum > target):
                presum -= nums[l]
                l += 1
            if(presum == target):
                maxlen = max(maxlen, r - l + 1)

        if maxlen == -1:
            return -1

        return len(nums) - maxlen