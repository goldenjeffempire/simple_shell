#include "joshell.h"

/**
 * jdelete_node_at_ind - deletes node at given index
 * @hd: address of pointer to first node
 * @ind: ind of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int jdelete_node_at_ind(list_t **hd, unsigned int ind)
{
	list_t *node, *prev_node;
	unsigned int j = 0;

	if (!hd || !*hd)
		return (0);

	if (!ind)
	{
		node = *hd;
		*hd = (*hd)->next;
		jfree((*node).jstr);
		free(node);
		return (1);
	}
	node = *hd;
	while (node)
	{
		if (j == ind)
		{
			(*prev_node).next = (*node).next;
			jfree((*node).jstr);
			free(node);
			return (1);
		}
		j++;
		prev_node = node;
		node = (*node).next;
	}
	return (0);
}
