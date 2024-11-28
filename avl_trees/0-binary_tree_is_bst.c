#include <limits.h>
#include "binary_trees.h"

/**
 * get_max_value - find the max value in a tree
 * @tree: Pointer to the root of the tree
 *
 * Return: the maximum value in the tree, or INT_MIN if tree is null
 */
static int get_max_value(const binary_tree_t *tree)
{
	int left_max, right_max;

	if (tree == NULL)
		return (INT_MIN);

	left_max = get_max_value(tree->left);
	right_max = get_max_value(tree->right);

	if (tree->n > left_max && tree->n > right_max)
		return (tree->n);

	return (left_max > right_max ? left_max : right_max);
}

/**
 * get_min_value - find the min value in a tree
 * @tree: Pointer to the root of the tree
 *
 * Return: the minimum value in the tree, or INT_MAX if tree is null
 */
static int get_min_value(const binary_tree_t *tree)
{
	int left_min, right_min;

	if (tree == NULL)
		return (INT_MAX);

	left_min = get_min_value(tree->left);
	right_min = get_min_value(tree->right);

	if (tree->n < left_min && tree->n < right_min)
		return (tree->n);

	return (left_min < right_min ? left_min : right_min);
}

/**
 * binary_tree_is_bst - Check if the tree is an bst tree
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if the tree is bst, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && get_max_value(tree->left) >= tree->n)
		return (0);

	if (tree->right && get_min_value(tree->right) <= tree->n)
		return (0);

	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
}
