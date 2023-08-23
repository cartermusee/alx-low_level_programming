#!/usr/bin/python3
"""function to calculated perimeter land water"""


def island_perimeter(grid):
    """function itself
    arg:
        grid:which is a list
    return:perimeter"""
    perimeter = 0
    row, col = len(grid), len(grid[0])

    for i in range(row):
        for j in range(col):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
