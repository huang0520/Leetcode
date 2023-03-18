class Solution:
    def twoSum(self, nums: list[int], target: int) ->list[int]:
        table = {}
        for i in enumerate(nums):
            if (table.__contains__(target - i[1])): return [table[target - i[1]], i[0]]
            table[i[1]] = i[0]
        return [-1, -1]
        
        
        
nums = [0, 0]
target = 0

sol = Solution()
print(sol.twoSum(nums, target))