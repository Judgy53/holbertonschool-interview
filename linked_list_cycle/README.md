# linked_list_cycle
Write a function in C that checks if a singly linked list has a cycle in it.

**Requirements**
- Prototype: `int check_cycle(listint_t *list);`
- Return: 0 if there is no cycle, 1 if there is a cycle

- Only these functions are allowed: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")

---
- Out Files: `0-check_cycle.c, lists.h`
- Given Files: [lists.h](lists.h), [0-linked_lists.c](0-linked_lists.c), [0-main.c](0-main.c)
- Expected output :
```sh
$ gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
$ ./cycle 
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
$
```