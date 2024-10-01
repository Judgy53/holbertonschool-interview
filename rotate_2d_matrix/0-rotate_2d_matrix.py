#!/usr/bin/python3
"""Module rotate_2d_matrix"""


def rotate_2d_matrix(matrix):
    """Rotate a 2d matrix 90 degree clockwise"""
    matrix[:] = [list(row) for row in zip(*matrix[::-1])]
