from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        """
        Binary Search on Answer

        Search for the minimum ship capacity that allows shipping
        all packages within the given number of days.
        """

        # Minimum possible capacity is the heaviest package.
        low = max(weights)

        # Maximum possible capacity is shipping everything in one day.
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