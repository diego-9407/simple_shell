#include "shell.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: double pointer to the head of the list
 * @trash: number to add
 * Return: the address of the new element, or NULL if it failed
 */
garbage *add_nodeint_end(garbage **head, void *trash)
{
	garbage *new_end_list = NULL;
	garbage *temp = *head;

	new_end_list = malloc(sizeof(garbage));
	if (!new_end_list)
		return (NULL);
	new_end_list->trash = trash;
	new_end_list->next = NULL;
	if (!*head)
	{
		*head = new_end_list;
	}
	else
	{
		while (temp && temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_end_list;
	}
	return (*head);
}

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: head of the list
 * Return: the number of nodes.
 */
void print_listint(garbage *h)
{
	int num_of_nodes = 0;

	while (h)
	{
		printf("%p\n", h->trash);
		h = h->next;
		num_of_nodes++;
	}
	printf("el numero de nodos es: %i\n", num_of_nodes);
}
/**
 * free_list -function that frees a list_t list.
 * @head: head of the list
 */
void free_list(garbage *head)
{
	garbage *copy_head;

	while (head)
	{
		copy_head = head->next;
		free(head->trash);
		free(head);
		head = copy_head;
	}
}
