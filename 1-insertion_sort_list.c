#include "sort.h"
/**
 * insertion_sort_list - sort a list
 * @list: UnSorted Linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = s_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *s_node - swap a node helper
 *@node: node
 *@list: node list
 *Return: return pointer of current node
 */

listint_t *s_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *curt = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = curt->next;
	if (curt->next)
		curt->next->prev = back;
	curt->next = back;
	curt->prev = back->prev;
	back->prev = curt;
	if (curt->prev)
		curt->prev->next = curt;
	else
		*list = curt;
	return (curt);
}
