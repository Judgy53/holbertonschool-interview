#!/usr/bin/python3
"""Module rain
"""


def rain(walls):
    """Calculate how many units of water will be retained after it rains
    """
    total = 0
    max_left = 0
    for i, height in enumerate(walls):
        max_right = max(walls[i+1:]) if i < (len(walls) - 1) else 0
        total += max([min([max_left, max_right]) - height, 0])
        max_left = max([max_left, height])

    return total
