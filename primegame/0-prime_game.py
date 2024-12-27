#!/usr/bin/python3
"""
Prime Game Module
"""

def generate_primes_up_to(n):
    """
    Generate a list of prime numbers up to a given number.

    Args:
        n (int): The upper limit (inclusive) for generating prime numbers.

    Returns:
        list: A list of prime numbers up to `n`.
    """
    primes = []
    sieve = [True] * (n + 1)
    for i in range(2, n + 1):
        if sieve[i]:
            primes.append(i)
            for multiple in range(i * 2, n + 1, i):
                sieve[multiple] = False
    return primes


def isWinner(x, nums):
    """
    Determine the winner of a prime number game played between Maria and Ben.

    Args:
        x (int): The number of rounds.
        nums (list of int): A list of numbers, where each number represents
                            the upper limit for primes in that round.

    Returns:
        str: The name of the player who won the most rounds (`Maria` or `Ben`),
             or `None` if there is a tie or invalid input.
    """
    if x < 1 or not nums:
        return None

    primes = generate_primes_up_to(max(nums))
    maria = 0
    ben = 0

    for n in nums:
        if sum(p <= n for p in primes) % 2 == 1:
            maria += 1
        else:
            ben += 1

    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return None
