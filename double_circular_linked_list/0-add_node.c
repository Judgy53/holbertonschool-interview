#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - add a new node at the end of the double linked list
 *
 * @list: double pointer to the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node = malloc(sizeof(List));

	if (!node)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}

	if (!(*list))
	{
		node->prev = node;
		node->next = node;
		*list = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;

		if ((*list)->prev)
			(*list)->prev->next = node;
		(*list)->prev = node;
	}

	return (node);
}

/**
 * add_node_begin - add a new node at the beginning of the double linked list
 *
 * @list: double pointer to the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	node = add_node_end(list, str);
	*list = node;
	return (node);
}
