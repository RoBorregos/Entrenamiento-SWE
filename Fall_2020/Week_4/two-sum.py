'''
Problem: https://leetcode.com/problems/two-sum/

Approach: Cycle through possible combinations until one is found.
            
Time complexity: O(n^2)

Space complexity: O(1)
'''

def twoSum(nums, target):
    for i, num in enumerate(nums):
        if (target - num in nums): 
            for j in range(i + 1, len(nums)):
                if num + nums[j] == target:
                    return [i, j]

print(twoSum([2,7,11,15], 9))
