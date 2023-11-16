#include "joshell.h"

/**
 * check_chain - function checks if we should continue chaining
 * based on last status in the code
 * @jinfo:pointer to the parameter struct
 * @buf: this is pointing to char buffer
 * @f: this pointer addresses the present position in buf
 * @i: the initiating position in buf
 * @len: pointer of the length of buf
 * Return: Void
 */
void check_chain(jinfo_a *jinfo, char *buf, size_t *f, size_t i, size_t len)
{
        size_t j = *f;

        if ((*jinfo).cmd_buf_type == JOMD_AND)
        {
                if ((*jinfo).status)
                {
                        buf[i] = 0;
                        j = len;
                }
        }
        if ((*jinfo).cmd_buf_type == JOMD_OR)
        {
                if (!(*jinfo).status)
                {
                        buf[i] = 0;
                        j = len;
                }
        }

        *f = j;
}
