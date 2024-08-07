#!/usr/bin/python3
""" nqueens module
"""
import sys


def nqueens(n):
    """ Solves the N queen problem.
    Returns an array of all possible solutions for a board of size `n`
    """
    if not isinstance(n, int):
        print("N must be a number")
        return

    if n < 4:
        print("N must be a number")
        return

    return __solve__(n, [])


def __solve__(n, placed_queens):
    """ Tries all solutions through recursive backtracking
    Returns an array of all found solutions
    """
    x = len(placed_queens)
    for y in range(n):
        if not __is_safe_position__(placed_queens, x, y):
            continue

        placed_queens.append([x, y])

        __solve__(n, placed_queens)
        if len(placed_queens) == n:
            print(placed_queens)

        placed_queens.pop()


def __is_safe_position__(placed_queens, x, y):
    """ Check if a position is safe
    Returns True if no queen attacks that position, False otherwise
    """
    for [qx, qy] in placed_queens:
        # cardinal check
        if qx == x or qy == y:
            return False

        # diagonal check
        if abs(x - qx) == abs(y - qy):
            return False
    return True


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    size = int(sys.argv[1]) if sys.argv[1].isdigit() else None
    nqueens(size)
