#!/usr/bin/python3
"""
Main Module
"""

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3, 11, 17])))
