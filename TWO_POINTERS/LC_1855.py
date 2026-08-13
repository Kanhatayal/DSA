from typing import List

class solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        n, m, i, j, result = len(nums1), len(nums2), 0, 0, 0

        while i < n and j < m:
            if nums1[i] > nums2[j]:
                i += 1
            else:
                result = max(result, j - i)
                j += 1
        return result

if __name__ == "__main__":
    obj = solution()
    nums1 = [55,30,5,4,2]
    nums2 = [25,25,25,25,25]
    print(obj.maxDistance(nums1, nums2))

