#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t s = 0;
	size_t len_r = 0;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		s = getline(buf, &len_r, stdin);
#else
		s = _getline(info, buf, &len_r);
#endif
		if (s > 0)
		{
			if ((*buf)[s - 1] == '\n')
			{
				(*buf)[s - 1] = '\0'; /* remove trailing newline */
				s--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = s;
				info->cmd_buf = buf;
			}
		}
	}
	return (s);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t j, k, len;
	ssize_t s = 0;
	char **buf_r = &(info->arg), *r;

	_putchar(BUF_FLUSH);
	s = input_buf(info, &buf, &len);
	if (s == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		k = j; /* init new iterator to current buf position */
		r = buf + j; /* get pointer for return */

		check_chain(info, buf, &k, j, len);
		while (k < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &k))
				break;
			k++;
		}

		j = k + 1; /* increment past nulled ';'' */
		if (j >= len) /* reached end of buffer? */
		{
			j = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_r = r; /* pass back pointer to current command position */
		return (_strlen(r)); /* return length of current command */
	}

	*buf_r = buf; /* else not a chain, pass back buffer from _getline() */
	return (s); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: s
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t s = 0;

	if (*i)
		return (0);
	s = read(info->readfd, buf, READ_BUF_SIZE);
	if (s >= 0)
		*i = s;
	return (s);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: t
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, len;
	size_t l;
	ssize_t s = 0, t = 0;
	char *r = NULL, *new_r = NULL, *d;

	r = *ptr;
	if (r && length)
		t = *length;
	if (j == len)
		j = len = 0;

	s = read_buf(info, buf, &len);
	if (s == -1 || (s == 0 && len == 0))
		return (-1);

	d = _strchr(buf + j, '\n');
	l = d ? 1 + (unsigned int)(d - buf) : len;
	new_r = _realloc(r, t, t ? t + l : l + 1);
	if (!new_r) /* MALLOC FAILURE! */
		return (r ? free(r), -1 : -1);

	if (t)
		_strncat(new_r, buf + j, l - j);
	else
		_strncpy(new_r, buf + j, l - j + 1);

	t += l - j;
	j = l;
	r = new_r;

	if (length)
		*length = t;
	*ptr = r;
	return (t);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
