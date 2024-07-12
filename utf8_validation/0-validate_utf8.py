#!/usr/bin/python3
""" validate_utf8 Module
"""


def validUTF8(data):
    """ Determines if a given data set 
        represents a valid UTF-8 encoding.
    """
    char_byte_left = 0
    for entry in data:
        entryByte = entry & 0b11111111

        if char_byte_left == 0:
            shift = 7
            while entryByte >> shift & 1:
                char_byte_left += 1
                shift -= 1
            if char_byte_left > 4:
                return False
        else:
            continue_identifier = entryByte >> 6
            if continue_identifier != 0b10:
                return False
            char_byte_left -= 1

    return char_byte_left == 0
