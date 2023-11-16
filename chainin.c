#include "joshell.h"

/**
 * jchain - function tests if current char in buffer is a chain delimeter
 * @jinfo: the parameter struct
 * @buf: the char buffer pointer
 * @f: this is address of current position in buf
 * Return: 1 if successful, else 0
 */
int jchain(jinfo_a *jinfo, char *buf, size_t *f)
{
        size_t j = *f;

        if (buf[j] == '|' && buf[j + 1] == '|')
        {
                buf[j] = 0;
                j++;
                (*jinfo).cmd_buf_type = JOMD_OR;
        }
        else if (buf[j] == '&' && buf[j + 1] == '&')
        {
                buf[j] = 0;
                j++;
                (*jinfo).cmd_buf_type = JOMD_AND;
        }
        else if (buf[j] == ';')
        {
                buf[j] = 0;
                (*jinfo).cmd_buf_type = JOMD_CHAIN;
        }
        else
                return (0);
        *f = j;
        return (1);
}
