#!/usr/bin/python3
"""
island_perimeter module
"""

adjacent_offset = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def is_land(grid, x, y):
    """
    Returns true if grid cell at (x, y) is land, false otherwise
    """
    if not (0 <= y < len(grid) or 0 <= x < len(grid[y])):
        return False

    return grid[y][x]


def island_perimeter(grid):
    """
    Compute and returns the perimeter of the island described in `grid`
    """
    perimeter = 0

    for y in range(len(grid)):
        row = grid[y]
        for x in range(len(row)):
            cell = row[x]
            if cell == 0:
                continue
            adjacent_water = 4
            for off_x, off_y in adjacent_offset:
                if is_land(grid, x + off_x, y + off_y):
                    adjacent_water -= 1
            perimeter += adjacent_water

    return perimeter
