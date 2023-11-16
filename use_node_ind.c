#include "joshell.h"

/**
 * use_node_ind - this function gets the index of a node
 * @hd: pointer to list head
 * @node: pointer to the node
 * Return: -1
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
