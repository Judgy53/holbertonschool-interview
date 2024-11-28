# wild_cmp
Write a function that compares two strings and returns `1` if the strings can be considered identical, otherwise return `0`.
- Prototype: `int wildcmp(char *s1, char *s2);`
- `s2` can contain the special character `*`.
- The special char `*` can replace any string (including an empty string)
- File: `0-wildcmp.c`

```sh
$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
$ ./0-wildcmp
1
1
1
1
1
1
1
0
1
1
0
0
$
```
