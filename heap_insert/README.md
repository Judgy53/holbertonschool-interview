# heap_insert
Write a function in C that inserts a number into a Max Binary Heap.

**Requirements**
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")

**Print function**

To match the examples in the tasks, you are given [this function](https://github.com/hs-hq/0x1C.c "binary_tree_print.c")
This function is used only for visualisation purpose. It may not be used during the correction.

## 0. New node

Write a function that creates a binary tree node:
- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- `parent` is a pointer to the parent node of the node to create
- `value` is the value to put in the new node
- When created, a node does not have any children
- Your function must return a pointer to the new node, or `NULL` on failure

- File: `0-binary_tree_node.c`


**Expected output**

- 0-main.c (only used for testing) :

```c
#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}
```

- Compilation and execution:
```sh
$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
```