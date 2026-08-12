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