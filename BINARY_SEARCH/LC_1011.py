from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low = max(weights)
        high = sum(weights)

        while low <= high:
            capacity = (low + high) // 2

            required_days = 1
            current_weight = 0

            # Simulate shipping with the current capacity.
            for weight in weights:
                if current_weight + weight <= capacity:
                    current_weight += weight
                else:
                    required_days += 1
                    current_weight = weight

            # Capacity is sufficient, try a smaller one.
            if required_days <= days:
                high = capacity - 1
            else:
                # Capacity is too small.
                low = capacity + 1

        return low

if __name__  == "__main__":
    object = Solution()
    weights = [1,2,3,4,5,6,7,8,9,10]
    days = 5
    print(object.shipWithinDays(weights, days))