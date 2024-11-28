#include "binary_trees.h"
#include "0-binary_tree_is_bst.c"

/**
 * tree_height - Compute the max height of a tree
 * @tree: Pointer to the root of the tree
 *
 * Return: the max height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int height_l;
	int height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + tree_height(tree->left) : 1;
	height_r = tree->right ? 1 + tree_height(tree->right) : 1;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * is_balanced - Check if the tree's height is balanced
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if the tree is balanced, 0 otherwise
 */
static int is_balanced(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (abs(tree_height(tree->left) - tree_height(tree->right)) > 1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Check if the tree is an avl tree
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if the tree is avl, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL || tree->right == NULL)
		return (1);

	return (binary_tree_is_bst(tree) && is_balanced(tree));
}
