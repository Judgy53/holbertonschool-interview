#include <stdlib.h>
#include <stdio.h>

#include "lists.h"

/**
 * find_middle_of_list - find the last node of the first half of the list
 * @head: pointer to head of the list
 * Return: address of the middle node
 */
static listint_t *find_middle_of_list(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = slow->next;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return (slow);
}

/**
 * reverse_list - reverse the order of the list
 * @head: pointer to the head of the list
 * Return: address to the new head of the list
 */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *tmp = NULL;
	listint_t *previous = NULL;
	listint_t *current = head;

	while (current != NULL)
	{
		tmp = current->next;
		current->next = previous;
		previous = current;
		current = tmp;
	}

	return (previous);
}

/**
 * is_palindrome - Check if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *middle, *first, *second;
	int result = 1;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (1);
	}

	middle = find_middle_of_list(*head);
	second = reverse_list(middle->next);
	first = *head;

	while (first !=  NULL && second != NULL)
	{
		if (first->n != second->n)
		{
			result = 0;
			break;
		}

		first = first->next;
		second = second->next;
	}

	/* Restore second half to its original state */
	reverse_list(middle->next);

	return (result);
}
