class Solution:
    def containsDuplicate(self, nums: list) -> bool:
        unique = {}
        for i in nums:
            try:
                unique[i]
                return True
            except KeyError:
                unique[i] = i
                
        return False
    
print(Solution.containsDuplicate(1, nums = [1, 2, 3, 1]))