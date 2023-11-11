#include "joshell.h"

/**
 * use_node_ind - gets the index of a node
 * @hd: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t use_node_ind(list_t *hd, list_t *node)
{
	size_t j = 0;

	while (hd)
	{
		if (hd == node)
			return (j);
		hd = hd->next;
		j++;
	}
	return (-1);
}
