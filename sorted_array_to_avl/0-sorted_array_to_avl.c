#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl_node - Creates a node in the AVL tree.
 * Uses recursion to create all child nodes
 * @array: Pointer to the first element of the sorted array.
 * @size: Size of the array.
 * @root: Pointer to the root node of the tree.
 * Return: Pointer to the created node, or NULL if failed.
 */
static avl_t *sorted_array_to_avl_node(int *array, size_t size, avl_t *root)
{
	avl_t *node;
	int index_middle, size_left, size_right;
	int *array_left, *array_right;

	if (size == 0)
		return (NULL);

	node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

	index_middle = (size - 1) / 2;

	array_left = array;
	size_left = index_middle;

	array_right = array + index_middle + 1;
	size_right = size - index_middle - 1;

	node->n = array[index_middle];
	node->left = sorted_array_to_avl_node(array_left, size_left, node);
	node->right = sorted_array_to_avl_node(array_right, size_right, node);
	node->parent = root;

	return (node);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 * @array: Pointer to the first element of the sorted array.
 * @size: size of the array.
 * Return: Pointer to the root node of the tree, or NULL if failed.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (sorted_array_to_avl_node(array, size, NULL));
}
