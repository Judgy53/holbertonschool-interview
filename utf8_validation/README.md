# utf8_validation
Write a method that determines if a given data set represents a valid UTF-8 encoding.

**Requirements**
- Prototype: `def validUTF8(data)`
- Return: `True` if data is a valid UTF-8 encoding, else return `False`
- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

---
- Out Files: `0-validate_utf8.py`
- Given Files: [0-main.py](0-main.py)
- Expected output :
```sh
$ ./0-main.py
True
True
False
$
```