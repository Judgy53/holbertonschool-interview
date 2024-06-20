#!/usr/bin/python3
"""
LogParser Module.
Provides a LogParser class that parses request log from stdin
"""
import sys

line_count = 0
file_size = 0
code_hits = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}


def print_stats(file_size, code_hits) -> None:
    """
    Print the current parsing stats
    """
    print(f'File size: {file_size}')
    for code in code_hits:
        hits = code_hits[code]
        if hits == 0:
            continue
        print(f'{code}: {hits}')


try:
    while True:
        input = sys.stdin.readline()
        line_count += 1

        split_line = input.split(' ')
        if len(split_line) < 2:
            continue

        code = split_line[-2]
        try:
            size = int(split_line[-1])
        except Exception:
            continue

        if code not in code_hits:
            continue

        code_hits[code] += 1
        file_size += size
        if line_count % 10 == 0:
            print_stats(file_size, code_hits)
except KeyboardInterrupt:
    print_stats(file_size, code_hits)
