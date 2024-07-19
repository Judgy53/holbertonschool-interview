#!/usr/bin/python3
""" validate_utf8 Module
"""


def validUTF8(data):
    """ Determines if a given data set
        represents a valid UTF-8 encoding.
    """
    # Number of bytes left to process in the current char
    char_byte_left = 0
    for entry in data:
        # Extract least significant byte from number
        entryByte = entry % 0b11111111

        if char_byte_left == 0:
            # Count leading 1's to know how many bytes in character
            shift = 7
            while entryByte >> shift & 1:
                char_byte_left += 1
                shift -= 1

            # Continue if single byte char to avoid decrementing
            if char_byte_left == 0:
                continue

            # Detect invalid byte count
            if char_byte_left == 1 or char_byte_left > 4:
                return False
        elif entryByte >> 6 != 0b10:
            return False

        char_byte_left -= 1

    return char_byte_left == 0
