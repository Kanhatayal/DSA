from typing import list

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        starts = [(interval[0], i) for i, interval in enumerate(intervals)]
        starts.sort()
        res = []
        for interval in intervals:
            end = interval[1]
            left, right = 0, len(starts) - 1
            idx = -1
            while left <= right:
                mid = (left + right) // 2
                if starts[mid][0] >= end:
                    idx = starts[mid][1]
                    right = mid - 1
                else:
                    left = mid + 1
            res.append(idx)
        return res

if __name__ == "__main__":
    obj = Solution()
    intervals = [[1,4],[2,3],[3,4]]
    print(obj.findRightInterval(intervals))