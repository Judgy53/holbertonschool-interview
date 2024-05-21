#include <stdlib.h>
#include "binary_trees.h"

/**
 * count_complete_depth - count child nodes that are complete
 * @root: pointer to the root of the tree
 * Return: depth of the binary tree
*/
static int count_complete_depth(binary_tree_t *root)
{
	int depth_left = 0;
	int depth_right = 0;

	if (root == NULL || root->left == NULL || root->right == NULL)
		return (0);

	depth_left = count_complete_depth(root->left);
	depth_right = count_complete_depth(root->right);

	if (depth_left > depth_right)
		return (depth_left + 1);

	return (depth_right + 1);
}

/**
 * find_insert_parent - find where to insert a new node
 * @root: pointer to the root of the tree
 * Return: pointer to the parent of the correct insert position
*/
static heap_t *find_insert_parent(binary_tree_t *root)
{
	if (root->left == NULL || root->right == NULL)
		return (root);

	if (count_complete_depth(root->left) == count_complete_depth(root->right))
		return (find_insert_parent(root->left));

	return (find_insert_parent(root->right));
}


/**
 * bubble_up_inserted_value - Ensure the new node respects Max Heap Ordering.
 * @new_node: pointer to the newly inserted node
 * Return: Pointer to the node containing the newly inserted value
*/
static heap_t *bubble_up_inserted_value(heap_t *new_node)
{
	if (new_node->parent != NULL && new_node->parent->n < new_node->n)
	{
		int temp = new_node->n;

		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		return (bubble_up_inserted_value(new_node->parent));
	}

	return (new_node);
}


/**
 * heap_insert - Insert a new value in a Max Heap Binary tree
 * @root: Pointer to the pointer to the root of the tree.
 * @value: new value to insert
 * Return: Pointer to the newly inserted node.
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *insert_parent;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new = binary_tree_node(*root, value);
	if (new == NULL)
		return (NULL);

	insert_parent = find_insert_parent(*root);
	if (insert_parent->left == NULL)
		insert_parent->left = new;
	else if (insert_parent->right == NULL)
		insert_parent->right = new;
	else
	{
		free(new);
		return (NULL);
	}

	new->parent = insert_parent;
	new = bubble_up_inserted_value(new);
	return (new);
}
