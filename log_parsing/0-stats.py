#!/usr/bin/python3
"""LogParser Module"""
import sys
import re


class LogParser():
    """LogParser class"""
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

    def run(self) -> None:
        """Infinite loop that parses stdin logs"""
        line_regex = re.compile((r'(?:[0-9]{1,3}\.?){4} - \[.*?\] '
                                 r'"GET /projects/260 HTTP/1.1" '
                                 r'([0-9]+) ([0-9]+)'))
        while True:
            input = sys.stdin.readline()

            match = re.match(line_regex, input)
            if match is None:
                continue

            code = match.group(1)
            try:
                size = int(match.group(2))
            except Exception:
                continue

            if code not in self.code_hits:
                continue

            self.code_hits[code] += 1
            self.file_size += size

            self.line_count += 1
            if self.line_count % 10 == 0:
                self.print_stats()

    def print_stats(self) -> None:
        """Print the current parser stats"""
        print(f'File size: {self.file_size}')
        for code in self.code_hits:
            hits = self.code_hits[code]
            if hits == 0:
                continue
            print(f'{code}: {hits}')


if __name__ == "__main__":
    parser = LogParser()
    try:
        parser.run()
    except KeyboardInterrupt:
        parser.print_stats()
