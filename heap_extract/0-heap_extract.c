#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _height - Compute the max height of a binary tree
 * @tree: Pointer to the root of the tree
 * Return: height of the tree
 */
static size_t _height(binary_tree_t *tree)
{
	size_t height_left = tree->left ? 1 + _height(tree->left) : 0;
	size_t height_right = tree->right ? 1 + _height(tree->right) : 0;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * find_last - Find the last level order node of the binary tree
 * @tree: pointer to the root node of the tree
 * @h: height of the tree
 * @layer: current recursive layer
 * Return: pointer to the last level order node, or NULL if not found
 */
static binary_tree_t *find_last(binary_tree_t *tree, size_t h, size_t layer)
{
	binary_tree_t *last_right;

	if (!tree)
	{
		return (NULL);
	}

	if (layer == h)
	{
		return (tree);
	}

	last_right = find_last(tree->right, h, layer + 1);
	if (last_right)
	{
		return (last_right);
	}

	return (find_last(tree->left, h, layer + 1));
}

/**
 * replace_with_last_level_order - Replace root node with last level order node
 * @root: Double pointer to the root of the heap tree
 */
static void replace_with_last_level_order(heap_t **root)
{
	binary_tree_t *last_order = find_last(*root, _height(*root), 0);

	if (last_order->parent->left == last_order)
	{
		last_order->parent->left = NULL;
	}
	if (last_order->parent->right == last_order)
	{
		last_order->parent->right = NULL;
	}
	last_order->parent = NULL;

	if ((*root)->left)
	{
		(*root)->left->parent = last_order;
	}
	if ((*root)->right)
	{
		(*root)->right->parent = last_order;
	}
	last_order->left = (*root)->left;
	last_order->right = (*root)->right;

	free(*root);
	*root = last_order;
}

/**
 * rebuild_heap - rebuild the heap to ensure max binary heap
 * @root: pointer to the root of the heap
 */
static void rebuild_heap(heap_t *root)
{
	heap_t *largest = root;

	if (root->left && root->left->n > largest->n)
	{
		largest = root->left;
	}

	if (root->right && root->right->n > largest->n)
	{
		largest = root->right;
	}

	if (largest != root)
	{
		root->n += largest->n;
		largest->n = root->n - largest->n;
		root->n -= largest->n;
		rebuild_heap(largest);
	}
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to the root node of the heap
 * Return: the value stored in the root node, or 0 if it fails
 */
int heap_extract(heap_t **root)
{
	int extracted;

	if (!root || !*root)
	{
		return (0);
	}

	extracted = (*root)->n;
	if (!(*root)->left)
	{
		free(*root);
		*root = NULL;
		return (extracted);
	}

	replace_with_last_level_order(root);
	rebuild_heap(*root);

	return (extracted);
}
