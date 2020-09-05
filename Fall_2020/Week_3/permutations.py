'''
Problem: https://leetcode.com/problems/permutations/

Approach: Generate next permutation until a cycle begins.
            
Time complexity: O(n^3)

Space complexity: O(n)
'''

def permute(nums):
    def nextPermutation(nums):
        if sorted(nums, reverse=True) == nums:
            return nums.sort()
        for i in reversed(range(len(nums))):
            if nums[i:] != list(reversed(sorted(nums[i:]))):
                for k in sorted(nums[i+1:]):
                    if k > nums[i]:
                        j = nums.index(k,i+1)
                        break
                nums[i],nums[j] = nums[j],nums[i]
                nums[i+1:] = sorted(nums[i+1:])
                return 
    
    if len(nums) <= 1:
        return [nums]
    nums.sort()
    perms = [nums]
    while True:
        a = perms[-1].copy()
        nextPermutation(a)
        perms.append(a)
        if perms[0] == perms[-1]:
            return perms[0:-1]

        
        
print(permute([1,2,3]))
