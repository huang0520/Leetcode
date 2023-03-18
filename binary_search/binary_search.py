class Solution:
    def search(self, nums: list[int], target: int) -> int:
        lp = 0
        rp = len(nums) - 1
        
        while (lp <= rp):
            mp = (lp + rp) >> 1
            if (nums[mp] < target): lp = mp + 1
            elif (nums[mp] > target): rp = mp - 1
            else: return mp
        return -1
        
        
nums = [-1,0,3,5,9,12]
target = 9

sol = Solution()
ans = sol.search(nums, target)
print(ans)