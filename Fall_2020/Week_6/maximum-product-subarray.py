'''
Problem: https://leetcode.com/problems/maximum-product-subarray/

Approach: Kadane's algorithm variant.
            
Time complexity: O(n)

Space complexity: O(1)
'''

def maxProduct(nums):
    if not nums:
        return 0
    maxVal, minVal, globalMax = nums[0], nums[0], nums[0]
    for i in range(1, len(nums)):
        maxVal, minVal = max(nums[i], nums[i]*maxVal, nums[i]*minVal), min(nums[i], nums[i]*maxVal, nums[i]*minVal)
        globalMax = max(globalMax, maxVal)
    return globalMax

arr = [2,3,-2,4]
val = maxProduct(arr)
print(val)
