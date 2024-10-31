# double_circular_linked_list
Create the source file `0-add_node.c` that contains the following functions:

- Add a new node to **the end** of a double circular linked list:
    - Prototype: `List *add_node_end(List **list, char *str);`
    - `List`: the list to modify
        - `str`: the string to copy into the new node
        - Returns: Address of the new node, or `NULL` on failure
- Add a new node to **the beginning** of a double circular linked list:
    - Prototype: `List *add_node_begin(List **list, char *str);`
    - `List`: the list to modify
        - `str`: the string to copy into the new node
        - Returns: Address of the new node, or `NULL` on failure
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")

```sh
$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
$ ./a.out
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
$
```
