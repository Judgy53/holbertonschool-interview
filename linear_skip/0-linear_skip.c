#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Search a value in a linear skip list
 * @head: Pointer to the head of the list
 * @value: value to search
 * Return: Pointer to the node found, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *start_node = head;
	skiplist_t *express_node;

	if (head == NULL)
	{
		return (NULL);
	}

	express_node = start_node->express;

	while (express_node != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
				express_node->index, express_node->n);
		if (express_node->n >= value)
			break;
		start_node = express_node;
		express_node = express_node->express;
	}

	if (express_node == NULL)
	{
		express_node = start_node;
		while (express_node->next != NULL)
			express_node = express_node->next;
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			start_node->index, express_node->index);

	while (start_node != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
				start_node->index, start_node->n);
		if (start_node->n == value)
			return (start_node);
		start_node = start_node->next;
	}
	return (NULL);
}
