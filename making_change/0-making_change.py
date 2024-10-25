#!/usr/bin/python3
"""
make_change Module
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins to reach total
    """
    if total <= 0:
        return 0

    minimum = [float('inf')] * (total + 1)
    minimum[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            minimum[amount] = min(minimum[amount], minimum[amount - coin] + 1)

    if minimum[total] == float('inf'):
        return -1

    return minimum[total]
