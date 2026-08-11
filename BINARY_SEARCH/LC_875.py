from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        while l <= r:
            mid = l + (r - l) // 2
            total_hours = 0
            for pile in piles:
                total_hours += (pile + mid - 1) // mid
            if total_hours <= h:
                r = mid - 1
            else:
                l = mid + 1
        return l


if __name__ == "__main__":
    obj = Solution()
    piles = [3, 6, 7, 11]
    h = 8
    print(obj.minEatingSpeed(piles, h))
