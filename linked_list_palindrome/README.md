# linked_list_palindrome
Write a function in C that checks if a singly linked list is a palindrome.

**Requirements**
- Prototype: `int is_palindrome(listint_t **head);`
- Return: `0` if it is not a palindrome, `1` if it is a palindrome
- An empty list is considered a palindrome

- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- File: `0-is_palindrome.c, lists.h`

---

Given files:

- [lists.h](lists.h)
- [linked_lists.c](linked_lists.c)

Expected output :

- [0-main.c](0-main.c) :
```sh
$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
$ ./palindrome
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```