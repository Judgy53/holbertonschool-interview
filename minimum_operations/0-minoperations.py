#!/usr/bin/python3
""" minOperations Module
"""


def minOperations(n):
    """ Calculates the fewest number of operations needed
        to result in exactly `n` characters in the file.
    """
    steps = 0
    file_len = 1
    clip_len = 0

    while file_len != n:
        if file_len > n:
            return 0

        if n % file_len == 0:
            clip_len = file_len
            steps += 1

        file_len += clip_len
        steps += 1

    return steps
