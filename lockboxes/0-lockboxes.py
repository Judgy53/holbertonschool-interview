#!/usr/bin/python3
"""
    Module that defines the function `canUnlockAll(boxes)`
    Example Usage:
        >>> print(canUnlockAll([[1], [2], [3], [4], []]))
        True
"""


def canUnlockAll(boxes):
    """Method that determines if all boxes can be opened"""
    boxCount = len(boxes)
    opened = []
    keys = [0]

    while len(keys) > 0:
        key = keys.pop(0)
        if key in opened or not (0 <= key < boxCount):
            continue

        opened.append(key)
        if len(opened) >= boxCount:
            return True

        for newKey in boxes[key]:
            keys.append(newKey)

    return False
