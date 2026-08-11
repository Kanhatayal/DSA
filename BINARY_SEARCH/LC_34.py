from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        index = [-1, -1]

        ans_index = -1
        l, r = 0, n - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                ans_index = mid
                r = mid - 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        index[0] = ans_index

        ans_index = -1
        l, r = 0, n - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                ans_index = mid
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        index[1] = ans_index

        return index


if __name__ == "__main__":
    obj = Solution()
    nums = [5, 7, 7, 8, 8, 10]
    target = 8
    print(obj.searchRange(nums, target))
