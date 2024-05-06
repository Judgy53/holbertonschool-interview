#!/usr/bin/python3
"""
    Module that defines the function `canUnlockAll(boxes)`
    Example Usage:
        >>> print(canUnlockAll([[1], [2], [3], [4], []]))
        True
"""


def canUnlockAll(boxes):
    """Method that determines if all boxes can be opened"""
    opened = []

    def openBox(i):
        if i in opened or len(opened) >= len(boxes):
            return
        opened.append(i)
        for key in boxes[i]:
            openBox(key)

    openBox(0)
    return len(opened) >= len(boxes)
