#include "joshell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @jstr: jstr field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *jstr, int numb)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	(*new_head).num = numb;
	if (jstr)
	{
		(*new_head).jstr = _strdup(jstr);
		if (!(*new_head).jstr)
		{
			free(new_head);
			return (NULL);
		}
	}
	(*new_head).next = *head;
	*head = new_head;
	return (new_head);
}
