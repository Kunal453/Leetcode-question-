# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).
# Example 1:
# Input: nums1 = [1,3], nums2 = [2]
# Output: 2.00000
# Explanation: merged array = [1,2,3] and median is 2.
# Example 2:
# Input: nums1 = [1,2], nums2 = [3,4]
# Output: 2.50000
# Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
# Constraints:
# nums1.length == m
# nums2.length == n
# 0 <= m <= 1000
# 0 <= n <= 1000
# 1 <= m + n <= 2000
# -106 <= nums1[i], nums2[i] <= 106 

  class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i=0
        j=0
        ans=[]
        n1=len(nums1)
        n2=len(nums2)
        while(i<n1 and j<n2):
            if nums1[i]>nums2[j]:
                ans.append(nums2[j])
                j+=1
            else:
                ans.append(nums1[i])
                i+=1
        if i<n1:
            for k in range(i,n1):
                ans.append(nums1[k])
        if j<n2:
            for k in range(j,n2):
                ans.append(nums2[k])
        print(ans)
        if len(ans)%2==0:
            return (ans[(len(ans)//2)-1]+ans[(len(ans)//2)])/2
        else:
            return ans[floor(len(ans)/2)]

        
