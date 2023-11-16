#include "joshell.h"

/**
 * free_list - function that frees all nodes of a list
 * @hd_ptr: address of double pointer to hd node
 * Return: void
 */
void free_list(list_t **hd_jptr)
{
        list_t *node, *next_node, *hd;

        if (!hd_jptr || !*hd_jptr)
                return;
        hd = *hd_jptr;
        node = hd;
        while (node)
        {
                next_node = (*node).next;
                jfree((*node).jstr);
                free(node);
                node = next_node;
        }
        *hd_jptr = NULL;
}
