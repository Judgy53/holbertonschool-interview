# linked_list_cycle
Write a function that checks whether or not a given unsigned integer is a palindrome.

**Requirements**
- Prototype: `int is_palindrome(unsigned long n);`
- Where `n` is the number to be checked
- Your function must return `1` if `n` is a palindrome, and `0` otherwise
- You are **not allowed** to allocate memory dynamically (malloc, calloc, …)

- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")

---
- Out Files: `0-is_palindrome.c, palindrome.h`
- Given Files: [0-main.c](0-main.c)
- Expected output :
```sh
$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
$ ./palindrome 1
1 is a palindrome.
$ ./palindrome 11
11 is a palindrome.
$ ./palindrome 112
112 is not a palindrome.
$ ./palindrome 121
121 is a palindrome.
$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
$
```