class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxdq = deque()
        mindq = deque()
        l = maxlen = 0
        for r in range(0, len(nums)):
            while(maxdq and nums[maxdq[-1]] < nums[r]):
                maxdq.pop()
            maxdq.append(r)

            while(mindq and nums[mindq[-1]] > nums[r]):
                mindq.pop()
            mindq.append(r)

            while(nums[maxdq[0]] - nums[mindq[0]] > limit):
                l += 1
                while(maxdq and maxdq[0] < l):
                    maxdq.popleft()

                while(mindq and mindq[0] < l):
                    mindq.popleft()

            maxlen = max(maxlen, r - l + 1)

        return maxlen
