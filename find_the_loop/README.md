# find_the_loop
Write a function that finds the loop in a linked list.

- Prototype: `listint_t *find_listint_loop(listint_t *head);`
- Returns: The address of the node where the loop starts, or `NULL` if there is no loop
- You are not allowed to use `malloc`, `free` or arrays
- You can only declare a maximum of two variables in your function
- - Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- File: `0-find_loop.c`

Note: In order to compile the main file, you are provided with [this static library](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/472/libloop.a "this static library"). This library won’t be used during the correction; Its only purpose is for testing.

```sh
$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
$ ./main
[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
$
```

If you want to use source file instead of the `libloop.a` library, please use this file [lib.c](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/text/2021/1/79eebf4f9215073644b8cd766a88c8a3f3a0fd88.c?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20241008%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20241008T073014Z&X-Amz-Expires=345600&X-Amz-SignedHeaders=host&X-Amz-Signature=11ebe2742f6de62917412a7d65d2f360b6b245de39df55745d380281751c0bb5 "lib.c")

And compile it with this command: `$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main`
